"let go_highlight_extra_types = 1

"template config
let g:template_load = 1
let g:template_tags_replacing = 1
let g:template_path = "/home/cheeray/.vim_runtime/template/"
let g:T_AUTHOR = "Huang Qiyu"
let g:T_AUTHOR_EMAIL = "cheeray.huang@gmail.com"
let g:T_DATE_FORMAT = "%m-%d-%Y %H:%M:%S"

"load tempalte plugin
source ~/.vim_runtime//template_loader.vim

"trim reducdant spaces in tail.
autocmd BufWrite * execute ":%s/[\t ]*$//g"

"keep 72 bytes at most per line in git commit message
autocmd Filetype gitcommit setlocal spell textwidth=72
