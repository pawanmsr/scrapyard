-- disable compatibility to old-time vi
vim.opt.compatible = false

vim.cmd([[
    " .vimrc
]])

require("plugins")

local builtin = require('telescope.builtin')
vim.keymap.set('n', '<leader>ff', builtin.find_files, {desc = 'Telescope find files'})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {desc = 'Telescope live grep'})
vim.keymap.set('n', '<leader>fb', builtin.buffers, {desc = 'Telescope buffers'})
vim.keymap.set('n', '<leader>fh', builtin.help_tags, {desc = 'Telescope help tags'})

require('nvim-treesitter.configs').setup{highlight={enable=true}}

local lspconfig = require('lspconfig')

local on_attach = function(client, bufnr)
    require('completion').on_attach(client)
    vim.lsp.inlay_hint.enable(true, { bufnr = bufnr })
end

-- requires rust analyzer binaries
-- https://rust-analyzer.github.io/manual.html
-- #rust-analyzer-language-server-binary
lspconfig.rust_analyzer.setup({
    on_attach = on_attach,
    settings = {
        ["rust-analyzer"] = {
            imports = {
                granularity = {
                    group = "module",
                },
                prefix = "self",
            },
            cargo = {
                buildScripts = {
                    enable = true,
                },
            },
            procMacro = {
                enable = true
            },
        }
    }
})
