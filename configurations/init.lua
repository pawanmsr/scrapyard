-- ~/.config/nvim/init.lua

-- disable compatibility to old-time vi
vim.opt.compatible = false

vim.cmd([[
    " .vimrc
    
    " syntax enable
    
    filetype on
    filetype indent on
    
    hi clear SpellBad
    hi SpellBad gui=undercurl

    set clipboard+=unnamedplus
]])

-- require is order sensitive
require("rc")
require("plugins")

local builtin = require('telescope.builtin')
vim.keymap.set('n', '<leader>ff', builtin.find_files, {desc = 'Telescope find files'})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {desc = 'Telescope live grep'})
vim.keymap.set('n', '<leader>fb', builtin.buffers, {desc = 'Telescope buffers'})
vim.keymap.set('n', '<leader>fh', builtin.help_tags, {desc = 'Telescope help tags'})

require("highlighter")
require("lsp")
require("on-the-rocks")
