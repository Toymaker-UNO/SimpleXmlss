#!/bin/bash
echo "Test Release"
g++ -W -Wall -I ./hpp -I ../release  ./src/test_main.cpp -o ./do
./do.exe
rm ./do.exe