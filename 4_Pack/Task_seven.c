#include <stdio.h>
#include <string.h>
void gisto(int symbol, int amount_of_symbols)
{
    printf("%c ", symbol+32);
    for (int step2 = 0; step2 < amount_of_symbols; ++step2)
    {
        printf("#");
    }
    printf("\n");
    // char resline[1000000];
    // memset(resline, '#', amount_of_symbols);
    // printf("%c %s", symbol, resline);
}
int main()
{
    // FILE * fp;
    // fp = fopen("input.txt", "r");
    int res[95];
    char line[1000000];
    for (int step = 0; step < 95; ++step)
    {
        res[step] = 0;
    }
    while (fgets(line, 1000, stdin) != NULL)
    {
        for(int step = 0; step < strlen(line);++step)
        {
            res[line[step]-32] ++;
        }
    }
    for (int step = 0; step < 95; ++step)
    {
        if (res[step] != 0)
        {
            gisto(step, res[step]);
        }
    }
    return 0;
}