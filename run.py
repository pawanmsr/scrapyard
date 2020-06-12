import argparse
from mittens import GloVe, Mittens
from sklearn.feature_extraction.text import CountVectorizer

from utils import GloVeUtility
from utils import read_txt, process_text, get_rare_tokens, filter_tokens

def get_arguments():
    """Get arguments

    Collect command line arguments as Argument Parser object.
    """

    parser = argparse.ArgumentParser(
        description="Fine Tune GloVe Vectors.",
        epilog="",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )

    parser.add_argument(
        "--path_to_glove",
        default="data/glove/glove.6B.300d.txt",
        type=str,
        help="Provide path to .txt file containing pretrained GloVe vectors.",
        dest="path_to_glove"
    )

    parser.add_argument(
        "--iter",
        default=1000,
        type=int,
        help="Maximum number of training iterations to run.",
        dest="iter"
    )

    parser.add_argument(
        "--path_to_document",
        type=str,
        help="Provide path to .txt document file.",
        dest="path_to_doc",
        required=True
    )

    parser.add_argument(
        "--remove_stopwords",
        action="store_true",
        help="Do not consider stopwords in document for training.",
        dest="remove_stopwords"
    )

    parser.add_argument(
        "--remove_punctuation",
        action="store_true",
        help="Do not consider isolated punctuations in document for training.",
        dest="remove_punctuation"
    )

    parser.add_argument(
        "--cased",
        action="store_true",
        help="Consider cased tokens instead of transforming them to lowercase.",
        dest="cased"
    )

    parser.add_argument(
        "--max_tokens",
        default=20000,
        type=int,
        help="Maximum number of tokens to consider for training.",
        dest="max_tokens"
    )

    parser.add_argument(
        "--min_freq",
        default=1,
        type=int,
        help="Minimum frequency of occurance for token to be considered for training.",
        dest="min_freq"
    )

    parser.add_argument(
        "--ngram_lower",
        default=1,
        type=int,
        help="Lower bound for ngram range.",
        dest="ngram_lower"
    )

    parser.add_argument(
        "--ngram_upper",
        default=1,
        type=int,
        help="Upper bound for ngram range.",
        dest="ngram_upper",
    )

    args, unknown = parser.parse_known_args()
    return args

def run(args):
    doc = read_txt(args.path_to_doc)
    doc_tokens = process_text(doc, lower=not args.cased,
        remove_stopwords=args.remove_stopwords, remove_punctuation=args.remove_punctuation)
    
    rare_tokens, selected_tokens = get_rare_tokens(doc_tokens, args.min_freq, args.max_tokens, return_non_rare=True)
    doc_tokens = filter_tokens(doc_tokens, rare_tokens)
    
    gu = GloVeUtility(args.path_to_glove)
    # oov_tokens = gu.get_oov_tokens(doc_tokens, as_set=True)

    vectorizer = CountVectorizer(
        ngram_range=(args.ngram_lower, args.ngram_upper),
        vocabulary=selected_tokens
    )
    count_vector = vectorizer.fit_transform([" ".join(doc_tokens)])
    
    csr_mat = count_vector.T * count_vector
    csr_mat.setdiag(0)
    
    cooccur_ar = csr_mat.toarray()

    mittens_model = Mittens(n=gu.d, max_iter=args.iter)
    new_embeddings = mittens_model.fit(
        cooccur_ar,
        vocab=selected_tokens,
        initial_embedding_dict=gu.vector_dict
    )

    new_embeddings = dict(zip(selected_tokens, new_embeddings))

    import pickle
    f = open("repo_glove.pkl","wb")
    pickle.dump(new_embeddings, f)
    f.close()

if __name__ == "__main__":
    args.get_arguments()
    pass