#!/bin/bash
echo "Test Release"
g++ -W -Wall -I ./hpp -I ../release  ./cpp/test_main.cpp -o ./do
./do.exe
rm ./do.exe