description of the file:

linearprobing.cpp
    the implementation of the algorithm for linear probing
    how to use:
        1. g++ linearprobing.cpp (to compile the code)
        2. ./linearprobing < data1_0.25_success.in (to run the code with input that can be generated from generatedata.cpp)
doublehashing.cpp
    the implementation of the algorithm for double hashing
    how to use:
        1. g++ doublehashing.cpp (to compile the code)
        2. ./doublehashing < data1_0.25_success.in (to run the code with input that can be generated from generatedata.cpp)
generatedata.cpp
    to generate the 3 dataset, NOTE: if you use windows, you need to fix the path to absolute path, eg: C:\\data
doublehash
    the appended result for all dataset using doublehash.cpp
linearprobing
    the appended result for all dataset using linearprobing.cpp
name.in
    a dataset list of people word name
data*.in
    a generated dataset in case you can't use generatedata.cpp
checkanswer.cpp
    a file to validate that our output from doublehashing and linearprobing is correct, implemented using C++ stl map
