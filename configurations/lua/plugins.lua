-- .config/lua/plugins.lua

local vim = vim
local Plug = vim.fn['plug#']

vim.call('plug#begin')

-- On-demand loading: loaded when the specified command is executed
Plug('preservim/nerdtree', {['on'] = 'NERDTreeToggle'})

-- Required for language services
Plug('autozimu/LanguageClient-neovim',
    {['branch'] = 'next', ['do'] = 'bash install.sh'})

-- Debug adapter
Plug('mfussenegger/nvim-dap')

-- Searching planets from telescope
Plug('nvim-lua/plenary.nvim')
Plug('nvim-telescope/telescope.nvim', {['branch'] = '0.1.x'})

Plug('nvim-treesitter/nvim-treesitter', {['do'] = ':TSUpdate'})
Plug('neovim/nvim-lspconfig') -- for editing on remote servers
Plug('ray-x/go.nvim')
Plug('ray-x/guihua.lua') -- recommended if need floating window support

vim.call('plug#end')
