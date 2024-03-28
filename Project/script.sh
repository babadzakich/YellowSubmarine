gcc -c ahoCorassic.c -o first.o
gcc -c grep.c -o grep.o
gcc grep.o first.o -o grep
