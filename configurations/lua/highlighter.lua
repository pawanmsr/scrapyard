-- treesitter configuration

require("nvim-treesitter.configs").setup {
    ensure_installed = {"c", "cpp", "rust", "python", "julia", "lua", "vim", "markdown"},
    sync_install = false,
    auto_install = true,
    highlight = {
      enable = true,
      
      disable = {"xml"},
      disable = function(lang, buf)
          local max_filesize = 1024 * 1024 -- 1 MB
          local ok, stats = pcall(vim.loop.fs_stat, vim.api.nvim_buf_get_name(buf))
          if ok and stats and stats.size > max_filesize then
              return true
          end
      end,
      
      additional_vim_regex_highlighting = false,
    },
  }