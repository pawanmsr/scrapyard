#!/bin/bash

GLOVE_DIR="glove"
mkdir -p $GLOVE_DIR
cd $GLOVE_DIR

# Uncomment the one that required to be downloaded.

##################################################

# Get GloVe vectors trained on 840B tokens
# if hash wget 2>/dev/null; then
#   wget http://downloads.cs.stanford.edu/nlp/data/glove.840B.300d.zip
# else
#   curl -O http://downloads.cs.stanford.edu/nlp/data/glove.840B.300d.zip
# fi

# unzip glove.840B.300d.zip
# rm glove.840B.300d.zip

##################################################

# Get GloVe vectors trained on 6B tokens
# if hash wget 2>/dev/null; then
#   wget http://downloads.cs.stanford.edu/nlp/data/glove.6B.zip
# else
#   curl -O http://downloads.cs.stanford.edu/nlp/data/glove.6B.zip
# fi

# unzip glove.6B.zip
# rm glove.6B.zip

##################################################

Get GloVe vectors trained on 42B tokens
if hash wget 2>/dev/null; then
  wget http://downloads.cs.stanford.edu/nlp/data/glove.42B.300d.zip
else
  curl -O http://downloads.cs.stanford.edu/nlp/data/glove.42B.300d.zip
fi

unzip glove.42B.300d.zip
rm glove.42B.300d.zip

##################################################