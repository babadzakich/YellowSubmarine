gcc -c ./zlib/minizip/unzip.c -I ./zlib/minizip -I ./zlib -DUSE_CRYPT
gcc -c ./zlib/minizip/ioapi.c -I ./zlib/minizip -I ./zlib -DUSE_CRYPT
gcc -c ./zlib/adler32.c -I ./zlib
gcc -c ./zlib/compress.c -I ./zlib
gcc -c ./zlib/crc32.c -I ./zlib
gcc -c ./zlib/deflate.c -I ./zlib
gcc -c ./zlib/gzclose.c -I ./zlib
gcc -c ./zlib/gzlib.c -I ./zlib
gcc -c ./zlib/gzread.c -I ./zlib
gcc -c ./zlib/gzwrite.c -I ./zlib
gcc -c ./zlib/infback.c -I ./zlib
gcc -c ./zlib/inffast.c -I ./zlib
gcc -c ./zlib/inflate.c -I ./zlib
gcc -c ./zlib/inftrees.c -I ./zlib
gcc -c ./zlib/trees.c -I ./zlib
gcc -c ./zlib/uncompr.c -I ./zlib
gcc -c ./zlib/zutil.c -I ./zlib
gcc -c -I ./zlib/ -I ./zlib/minizip/ test.c
gcc *.o -o checked_solution