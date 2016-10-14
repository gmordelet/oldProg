#!/bin/bash

sources='PrintToBase.c'

gcc -c $sources
ar rc libbook.a *.o
rm *.o
