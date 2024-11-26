Generic Configurations
======================

System, workspace, editors et cetera. Quick reference.

Editor
------

Checkout built-in user manual for scripting. Lua for Nvim.  

- *.vimrc* -> *.config/nvim/init.vim* (or *init.lua*)  

<details>
<summary>Notes</summary>
<br>
Version 8+ has built in manager for external scripts.  
Plugin manager requires independent installation but reduces effort in manual scripting. Prefer vim-plug or vundle.  

Sample: [.custom](/configurations/.custom/).
</details>

Lua5.4 and Vim-Plug. Prefer nvim build from source (switch to _stable_).  
Use either [init.vim](/configurations/init.vim) or [init.lua](/configurations/init.lua) but not both.

Language Server
---------------

Use toolchain installer to install the language and tools.

```shell
# Example
rustup component add rust-analyzer

```
