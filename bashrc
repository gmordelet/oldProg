# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# User specific aliases and functions
alias clean='find . \( -name "*~" -o -name "#*#" \) -print -delete'
alias gccW='gcc -Wall -Werror -Wextra'
