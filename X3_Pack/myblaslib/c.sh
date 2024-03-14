gcc -c level1.c -o level1.o
gcc -c level2.c -o level2.o
gcc -c level3.c -o level3.o
ar rcs myblas.a level1.o level2.o level3.o