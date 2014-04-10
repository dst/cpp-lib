#!/bin/bash

cd src

echo "Compiling..."
g++ -std=c++0x tests.cpp -o  tests

echo "Running..."
./tests