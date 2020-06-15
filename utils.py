import os
import io
import sys
import time
import string
import numpy as np
from collections import Counter
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

# en_stopwords = stopwords.words("english")

class progress_bar:
    """Progress bar

    Simple progress bar for displaying process progress.

    Attributes
    ----------
    last_print_len: int
        Length of the progress message printed by the previous call of std_print
    prev_time: float
        Private member
        TODO
    curr_time: float
        Private member
        TODO
    process_time: float
        Private member
        TODO
    print_length: int
        Private member
        Length of the progress message printed
    status: str
        Private member
        Status message printed with progress bar
    end: str
        Private member
        End character for print statement
    bar_length: int
        Private member
        Length of the progress bar
    num_processes: int
        Private member
        Number for sub-processes in the main process
    i: int
        Private member
        Sub-process index

    Methods
    -------
    std_print(text, start='\r', end='\n')
        Static method
        Prints a text message
    update_progress(i=None, is_index=True)
        Prints/updates the progress bar
    """

    last_print_len = None
    
    def __init__(self, num_processes, task="Task", bar_length=40):
        """
        Parameters
        ----------
        num_processes: int
            Number for sub-processes in the main process
        task: str
            Name of the task
        bar_length: int
            Length of progress bar
        """
        
        self._prev_time = None
        self._curr_time = None
        self._process_time = None
        self._print_length = 0
        self._status = ""
        self._end = ""
        self._bar_length = int(bar_length)
        
        if hasattr(num_processes, '__len__'):
            self._num_processes = len(num_processes)
        self._num_processes = int(num_processes)
        
        self._i = 0
        self.task = task

        self.std_print("Commencing {} . . .".format(task), end='')
        self._print_time = time.time()
        
        self.update_progress(self._i, is_index=False)
        self._start_time = time.time()

    @staticmethod
    def time_in_ms(time_x, time_y=None):
        """Time in minutes and seconds

        Parameters
        ----------
        time_x: float
            Elasped time or start time if time_y is provided
        time_y: float
            End time must be greater than start time
            If end time is not given then time_x is considered to be elasped time
        """
        
        if time_y is None:
            elapsed_time = time_x
        else:
            elapsed_time = time_y - time_x
        
        elapsed_mins = int(elapsed_time / 60)
        elapsed_secs = int(elapsed_time - (elapsed_mins * 60))
        
        return elapsed_mins, elapsed_secs
    
    @staticmethod
    def std_print(text, start='\r', end='\n'):
        """
        TODO
        """  
        
        curr_print = start + text
        if progress_bar.last_print_len is not None \
            and len(curr_print) < progress_bar.last_print_len:
            curr_print += ' '*(progress_bar.last_print_len - len(curr_print))
        curr_print += end

        if end != '\n':
            progress_bar.last_print_len = len(curr_print)
        else:
            progress_bar.last_print_len = None
        
        sys.stdout.write(curr_print)
        sys.stdout.flush()
    
    def update_progress(self, i=None, is_index=True):
        """Update progress

        Parameters
        ----------
        i: int
            Progess indicator
        is_index: bool
            Whether progress indicator starts from 0 or 1
        """

        if i is None:
            i = self._i
        
        if is_index:
            i += 1
        
        if i == 0:
            self._progress = 0
        elif i > 0 and i < self._num_processes:
            self._progress = float(i) / self._num_processes
        elif i == self._num_processes:
            self._progress = 1
        else:
            self._progress = -1

        self._curr_time = time.time()
        
        if self._prev_time is not None:
            remaining_processes = self._num_processes - i
            curr_process_time = self._curr_time - self._prev_time
            if self._process_time is None:
                self._process_time = curr_process_time
            else:
                self._process_time = 0.9 * self._process_time + 0.1 * curr_process_time
            etc_mins, etc_secs = self.time_in_ms(
                remaining_processes * self._process_time
            )

            self._status = "ETC: {}m {}s".format(etc_mins, etc_secs)
        
        if self._progress == 1:
            mins, secs = self.time_in_ms(time.time() - self._start_time)
            self._status = "Done. Time Taken: {}m {}s.".format(mins, secs)

        self._prev_time = self._curr_time

        fill = int(round(self._bar_length * self._progress))
        text = "Progress: [{}] {}% {}".format(
            '#'*fill + ' '*(self._bar_length - fill),
            round(self._progress*100, 2),
            self._status
        )
        
        curr_print_length = len(text)
        if curr_print_length < self._print_length:
            text += " "*(self._print_length - curr_print_length)
        self._print_length = max(len(text), self._print_length)

        if self._progress == 1:
            self._end = '\n'
        
        if (self._progress != -1 and time.time() - self._print_time > 1) \
            or self._progress == 1:
            self.std_print(text, end=self._end)
            self._print_time = time.time()
        
        if self._progress == 1:
            self.std_print("{} complete.".format(self.task))
        
        self._i += 1

class GloVeUtility:
    """
    TODO
    """

    def __init__(self, vector_path):
        self.vector_path = vector_path

        filename = vector_path.split(os.path.sep)[-1]
        
        vector_dims = [25, 50, 100, 200, 300]
        num_token_to_vocab_size = {
            6: int(400e3), # 400K
            42: int(1.9e6), # 1.9M
            840: int(2.2e6), # 2.2M
            27: int(1.2e6), # 1.2M
        }
        
        self.d = 300
        for dim in vector_dims:
            if "{}d".format(dim) in filename:
                self.d = dim
                break

        self.n = None
        for num in num_token_to_vocab_size:
            if "{}B".format(num) in filename:
                self.n = num_token_to_vocab_size[num]
                break
        
        if os.path.isfile(self.vector_path):
            self.vector_dict = self.load_vectors(
                self.vector_path,
                self.d,
                self.n
            )
        else:
            print("Vector path {} not found.".format(self.vector_path)) # change to logger error
            self.vector_dict = {}
    
    @staticmethod
    def load_vectors(fname, d, n=None):
        """
        TODO

        References
        ----------
            GloVe:
                Jeffrey Pennington, Richard Socher, and Christopher D. Manning. 2014. GloVe: Global Vectors for Word Representation.
                https://nlp.stanford.edu/pubs/glove.pdf
        """
        fin = io.open(fname, 'r', encoding='utf-8', newline='\n', errors='ignore')
        
        i=0
        if n:
            bar = progress_bar(n,"Loading glove vectors")
        else:
            progress_bar.std_print("Loading glove vectors . . . ", end='\r')
        
        data = {}
        for line in fin:
            line = line.strip()

            tokens = line.split()
            word = " ".join(tokens[0:len(tokens)-d])
            data[word] = np.array([float(val) for val in tokens[-d:]])

            i+=1
            if n:
                bar.update_progress(i)
        
        if not n:
            progress_bar.std_print("Loading glove vectors compete.")
        
        return data

    def compute_ngrams(self, token, min_n=2, max_n=8):
        ngrams = []
        for n in range(min_n, max_n + 1):
            for i in range(len(token) - n + 1):
                ngrams.append(token[i:i+n])
        return ngrams

    def get_vector(self, token, compute_unknown=False, norm=False):
        """
        TODO
        """
        
        if token in self.vector_dict:
            vec = np.array(self.vector_dict[token])
            return vec

        vec = np.zeros(self.d)
        if not compute_unknown:
            return vec

        ngrams_found = 0
        ngrams = self.compute_ngrams(token)
        for ngram in ngrams:
            if ngram in self.vector_dict:
                ngrams_found += 1
                
                ngram_vec = np.array(self.vector_dict[ngram])
                ngram_weight = float(np.linalg.norm(ngram_vec)) if norm else 1
                
                vec = vec + (ngram_vec / ngram_weight)
        
        vec = vec / max(1, ngrams_found)
        return vec
    
    def get_oov_tokens(self, tokens, as_set=False):
        oov_tokens = [token for token in tokens if token not in self.vector_dict.keys()]
        if as_set:
            return set(oov_tokens)
        return oov_tokens

def read_txt(file):
    doc = ""
    with open(file, mode='r', encoding="utf-8", errors="ignore") as f:
        doc = " ".join([line.strip() for line in f])
    return doc

def write_txt(path, data):
    with open(path, 'w') as f:
        for entry in data:
            f.write("{}\n".format(entry))

def process_text(text, lower=True, remove_stopwords=True, remove_punctuation=True):
    if lower:
        text = text.lower()
    
    punct = set(string.punctuation)
    en_stopwords = set(stopwords.words("english"))

    tokens_for_removal = set()
    if remove_punctuation:
        tokens_for_removal = tokens_for_removal.union(punct)
    if remove_stopwords:
        tokens_for_removal = tokens_for_removal.union(en_stopwords)
    
    tokens = word_tokenize(text)
    return [token for token in tokens if token not in tokens_for_removal]

def get_rare_tokens(tokens, min_freq, max_tokens=20000, return_non_rare=False):
    rare_tokens = []
    token_freq_tuples = []

    counts = Counter(tokens)
    for k in counts:
        count = counts[k]
        if count>=min_freq:
            token_freq_tuples.append((k,count))
        else:
            rare_tokens.append(k)

    token_freq_tuples = sorted(token_freq_tuples, key=lambda x: x[1], reverse=True)

    selected_tokens = []
    for i, (k,v) in enumerate(token_freq_tuples):
        if i < max_tokens:
            selected_tokens.append(k)
        else:
            rare_tokens.append(k)
    
    if return_non_rare:
        return rare_tokens, selected_tokens
    return rare_tokens

def filter_tokens(tokens, tokens_to_remove):
    tokens_to_remove = set(tokens_to_remove)
    return [token for token in tokens if token not in tokens_to_remove]