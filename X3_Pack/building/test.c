#include <stdio.h>
#include "unzip.h"

#define MAXSIZE 1<<20
char contents[MAXSIZE];
int num;

const char *ReadZip() {
    //open zip file and read text file inside it
    unzFile zf = unzOpen("input.zip");
    if (!zf)
        return "Failed to open input.zip";
    if (unzLocateFile(zf, "input.txt", 1) != UNZ_OK)
        return "Failed to locate input.txt in zip";
    if (unzOpenCurrentFilePassword(zf, "topsecret") != UNZ_OK)
        return "Failed to open file with password";
    int res = unzReadCurrentFile(zf, contents, MAXSIZE);
    if (res < 0)
        return "Failed to read file contents";
    if (unzClose(zf) != UNZ_OK)
        return "Failed to close zip file";
    num = res;
    return 0;
}

int main() {
    const char *err = ReadZip();
    if (err != 0) {
        printf("ERROR: %s\n", err);
        return 1;
    }

    //compute how often every char occurs
    char histo[256] = {0};
    for (int i = 0; i < num; i++)
        histo[(unsigned)contents[i]]++;

    //print frequences
    for (int i = 0; i < 128; i++) {
        printf("%3d: %3d  ", i, histo[i]);
        if (i % 16 == 15) printf("\n");
    }

    return 0;
}
