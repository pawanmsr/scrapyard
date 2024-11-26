" ~/.vim/plugins.vim

" PlugInstall
" PlugUpdate
" PlugClean
call plug#begin()

" On-demand loading: loaded when the specified command is executed
Plug 'preservim/nerdtree', {'on': 'NERDTreeToggle'}

" Required for language services
Plug 'autozimu/LanguageClient-neovim', {
    \ 'branch': 'next',
    \ 'do': 'bash install.sh',
    \ }

call plug#end()
