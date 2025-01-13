#!/bin/bash
echo "Test Development"
g++ -W -Wall -I ./hpp -I ../development  ./src/test_main.cpp -o ./do
./do.exe
rm ./do.exe