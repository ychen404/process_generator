se nu
set autoindent
set nocompatible              " be iMproved, required
filetype off                  " required
syntax enable

set term=xterm
" colo solarized8_dark_low
set laststatus=2
"Enable 256 color
set t_Co=256
" Show matches while searching
" set incsearch
" Search highlighting
"set hlsearch
"set fillchars+=stl:\ ,stlnc:\

"let g:Powerline_symbols='fancy'
" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'
" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
Plugin 'vim-airline/vim-airline'
" Useful plugins
Plugin 'scrooloose/nerdtree'
Plugin 'scrooloose/nerdcommenter'

" Color schemes
Plugin 'lifepillar/vim-solarized8'
Plugin 'altercation/vim-colors-solarized'
Plugin 'chriskempson/base16-vim'


" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

 let g:clang_library_path='/home/yitao/LLVM/llvm/build/lib'
