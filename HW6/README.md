## Files
Design choices are reflected within the comments of these individual files.
### tree.hh
Declaration of struct Tree and associated types and functions. 
### tree.cpp
Implementation of the functions defined within tree.hh. Documented extensively.
### test_tree.cpp
Tests the functions defined in tree.cpp with a bunch of assert statements, uses `cout` to tell you what it is  doing simultaneously.

## Build Instructions
From macOS terminal, run
`clang++ -std=c++17 -O3 -Wall -Wextra -Werror -pedantic -g test_tree.cpp -o test_tree`
to compile, and
`./test_tree`
to run.

I recompiled on an Ubuntu VM and checked for memory leaks with valgrind with the following command
`valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./test_tree`
It returned "No memory leaks possible".
### Expected Output
```Created tree centerN at 0x109401fc0 with key 1 and value 2
Created tree leftN at 0x109401f90 with key 1 and value 1
Created tree rightN at 0x109401f60 with key 1 and value 3
Node at LRLLLLL 0x0
Node at L 0x109401f90
Node at R 0x109401f60
Node at "" 0x109401fc0
Node at -1543j%klsdfa 0x0
Path to key 1 is L
Path to key 3 is -
Path to key -3 is -
Tree Deleted, program complete!```