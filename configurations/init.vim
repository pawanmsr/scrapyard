" disable compatibility to old-time vi
set nocompatible

" load from vim
set runtimepath^=~/.vim runtimepath+=~/.vim/after
let &packpath = &runtimepath
source ~/.vimrc

lua require('plugins')
