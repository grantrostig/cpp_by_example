#!/bin/sh
# mk_src - Prepares a project to be made via linux "make"
# ?? mk_make, mk_maker, pre_make
# Creates symlinked source code files into ./src & ./inc,
# from a single source directory to allow our Makefile to work, 
# which requires src/ and inc/. 
# It also symlinks the generic Makefile into project.
# Author: Grant Rostig
# License: Boost 1.0

CWD=$(pwd)
#ln -svri ../../Makefile_make_template/Makefile ${CWD}/Makefile

mkdir -v src inc
cd src
rm -i *.cpp
ln -sfiv ../*.cpp ./
cd ../inc
rm -i *.hpp
rm -i *.h
#ln -sfiv ../*.h   ./
ln -sfiv ../*.hpp ./
cd ..

