#!/bin/bash
echo "Test Development"
g++ -W -Wall -I ./hpp -I ../development  ./cpp/test_main.cpp -o ./do
./do.exe
rm ./do.exe

echo "Test Release"
g++ -W -Wall -I ./hpp -I ../release  ./cpp/test_main.cpp -o ./do
./do.exe
rm ./do.exe