@echo off
cd src
g++ main.cpp -o ../bin/out
cd..
cd bin
out
cd..
cmd /k