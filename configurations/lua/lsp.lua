local lspconfig = require('lspconfig')

local on_attach = function(client, bufnr)
    -- code completion
    require('completion').on_attach(client)
    -- names, annotations et cetera
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
