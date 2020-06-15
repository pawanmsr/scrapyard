import os
import argparse
from mittens import GloVe, Mittens
from sklearn.feature_extraction.text import CountVectorizer

from utils import GloVeUtility, progress_bar
from utils import read_txt, write_txt, process_text, get_rare_tokens, filter_tokens

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
        default="glove/glove.6B.300d.txt",
        type=str,
        help="Provide path to .txt file containing pretrained GloVe vectors.",
        dest="path_to_glove"
    )

    parser.add_argument(
        "--output",
        default="fine_tuned_glove",
        type=str,
        help="Output directory",
        dest="output"
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
        "--remove_rare",
        action="store_true",
        help="Remove rare tokens from the doc before computing co occurance matrix.",
        dest="remove_rare"
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

    args, _ = parser.parse_known_args()
    return args

def run(args):
    doc = read_txt(args.path_to_doc)
    doc_tokens = process_text(doc, lower=not args.cased,
        remove_stopwords=args.remove_stopwords, remove_punctuation=args.remove_punctuation)
    
    rare_tokens, selected_tokens = get_rare_tokens(doc_tokens, args.min_freq, args.max_tokens, return_non_rare=True)
    doc_tokens = filter_tokens(doc_tokens, rare_tokens)

    if args.remove_rare:
        doc_tokens = filter_tokens(doc_tokens, set(rare_tokens))

    gu = GloVeUtility(args.path_to_glove)

    vectorizer = CountVectorizer(
        ngram_range=(args.ngram_lower, args.ngram_upper),
        vocabulary=selected_tokens
    )
    count_vector = vectorizer.fit_transform([" ".join(doc_tokens)])
    
    csr_mat = count_vector.T * count_vector
    csr_mat.setdiag(0)
    
    cooccur_ar = csr_mat.toarray()

    mittens_model = Mittens(n=gu.d, max_iter=args.iter)
    embeddings = mittens_model.fit(
        cooccur_ar,
        vocab=selected_tokens,
        initial_embedding_dict=gu.vector_dict
    )

    embeddings_dict = dict(zip(selected_tokens, embeddings))
    embeddings_list = [" ".join(
        [key] + [str(val) for val in embeddings_dict[key]]
    ) for key in embeddings_dict]
    progress_bar.std_print("\nTrained on {} tokens.".format(len(embeddings_dict)))
    
    filename = args.path_to_glove.split(os.path.sep)[-1]
    savepath = os.path.join(args.output, filename)
    os.makedirs(args.output, exist_ok=True)
    write_txt(savepath, embeddings_list)

if __name__ == "__main__":
    args = get_arguments()
    run(args)