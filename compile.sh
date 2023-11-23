#!/bin/bash
bison -d parse.y
mv parse.tab.c parse.tab.cpp
sed -i -e 's/parse.tab.c/parse.tab.cpp/g' parse.tab.cpp
sed -i -e 's/parse.tab.h/parse.tab.hpp/g' parse.tab.cpp
mv parse.tab.h parse.tab.hpp
flex  lex.l
mv lex.yy.c lex.yy.cpp
g++ lex.yy.cpp parse.tab.cpp helper_functions.cpp