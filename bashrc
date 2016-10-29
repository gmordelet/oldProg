# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific aliases and functions

#PS1="\[\033[01;35m\][\u@\h\[\033[00m\]:\[\033[01;34m\]\w]\[\033[00m\]:\$ "
PS1="\[\033[01;35m\][\u@\h\[\033[00m\]:\[\033[01;37m\]\w]\[\033[00m\]:\$ "

export LS_COLORS="/users/licence/ib00895/.ls_colors"
eval `dircolors ~/.ls_colors`
unalias rm
alias clean='find . \( -name "*~" -o -name "#*#" \) -print -delete'
alias gccW='gcc -Wall -Werror -Wextra'
alias bgit='git add *.c *.sh *.a *.h && git commit -m "bgit" && git push'
function mex { touch $1 && chmod 700 $1; }
