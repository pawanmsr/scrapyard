" disable compatibility to old-time vi
set nocompatible

" load from vim
set runtimepath^=~/.vim runtimepath+=~/.vim/after
let &packpath = &runtimepath
source ~/.vimrc

lua require('plugins')

" install binary
" https://rust-analyzer.github.io/manual.html
" #rust-analyzer-language-server-binary
let g:LanguageClient_serverCommands = {
\ 'rust': ['rust-analyzer'],
\ }
