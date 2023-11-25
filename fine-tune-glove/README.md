Fine Tune GloVe
===============

Automated utility to fine tune GloVe embeddings.

Instructions
------------
1. clone repo  
`git clone https://github.com/pawanmsr/fine-tune-glove.git`  
2. Modify *get_glove.sh* to download required pretrained GloVe vectors from its [**Stanford** page](https://nlp.stanford.edu/projects/glove/). Run to download:  
`bash get_glove.sh`  
3. Supply command line arguments and run *run.py* to get the trained vectors. Run with **-h** flag for more details.  
`python run.py -h`  

Arguments
---------

- **max_tokens**: maximum number of tokens to consider for training.  
Since sparse matrix is used for co occurance matrix calculation, it is recommended to have number of tokens for training less than 20k. The number of tokens are capped based on their frequency of occurance.  
- **remove_rare**: remove rare tokens (tokens which are too few based on the *min_freq* and *max_tokens*) from the doc  
If rare tokens are not removed, they will be counted as bigram, trigra, e.t.c. without having adding to the co occurance matrix.  
- **ngram_lower** and **ngram_upper**: arguments for counting to obtain co occurance matrix.  
Example: if lower bound is 1 and upper bound is 3 then counting will firsr perform for unigram, then bigram, then trigram. If you only want counting to perform for trigram, then provide upper and lower both equal to 3.

Requirements
------------

### Necessary
- numpy
- nltk (with corpus for stopword)
- mittens
- scikit-learn

### Optional
- tensorflow

Tensorflow give atleast 10x faster training.
