" Basic vim run commands and configuration.
" Author: Canis Lupus Loner

" Keyboard mapping.
" noremap <Up> <Nop>
" noremap <Down> <Nop>
" noremap <Right> <Nop>
" noremap <Left> <Nop>

" set clipboard+=unnamedplus

" Editor commands.
" Reread files modified on disk.
set autoread

" Use auto-indent depending on the position of cursor.
set smartindent

" Line warp.
set wrap

" Display file title.
set title

" Enable spell checking.
set spell
" Set highlight style underline
hi clear SpellBad
hi SpellBad cterm=underline
" Set style for gVim
hi SpellBad gui=undercurl

" Display white-spaces.
set list

" Detect file-type.
filetype on

" Enable file-type specific indentation.
filetype indent on

" Use number of spaces depending on the location of the cursor.
set smarttab

" Use spaces instead of tabs.
set expandtab

" One tab equals 4 spaces.
set tabstop=4
set shiftwidth=4

" Be smart about case when searching.
set smartcase

" Highlight search results.
set hlsearch

" Highlight patter during search.
set incsearch

" Enable line number.
set number

" Display tab complete options as menu.
set wildmenu

" Enable syntax highlight.
syntax enable

" Standard English encoding.
set encoding=utf8

" Match brackets.
set showmatch

" Display current position.
set ruler

" Marker under current line.
set cursorline

" Marker for cursor column.
" set cursorcolumn

" Plugins for vim.
so ~/.vim/plugins.vim
