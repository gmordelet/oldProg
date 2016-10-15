#!/bin/bash

sources='PrintToBase.c BinSearch.c'

gcc -Werror -Wextra -Wall -c $sources
ar rc libbook.a *.o
rm *.o
