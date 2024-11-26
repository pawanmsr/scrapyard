-- ~/.config/nvim/init.lua

-- disable compatibility to old-time vi
vim.opt.compatible = false

vim.cmd([[
    " .vimrc
]])

-- order sensitive
require("plugins")
require("telescope-keymap")

require("rc")
require("lsp")

require('nvim-treesitter.configs').setup{highlight={enable=true}}
