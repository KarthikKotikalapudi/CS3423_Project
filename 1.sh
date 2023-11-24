#!/bin/bash
bison -d parse.y
mv parse.tab.c parse.tab.cpp
sed -i -e 's/parse.tab.c/parse.tab.cpp/g' parse.tab.cpp
flex  lex.l
mv lex.yy.c lex.yy.cpp
g++ lex.yy.cpp parse.tab.cpp Helper/helper_functions.cpp -o compiler