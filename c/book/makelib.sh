#!/bin/bash

sources='PrintToBase.c BinSearch.c GetLine.c'

gcc -Werror -Wextra -Wall -c $sources
ar rc libbook.a *.o
ranlib libbook.a
rm *.o
