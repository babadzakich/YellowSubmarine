#include <stdio.h>
#include <string.h>
char* concat(char *pref, char *suff)
{
    int step = 0;
    while(*(suff + step) != '\0')
    {
        *(pref + step) = *(suff + step);
        step++;
    }
    return pref+step;
}
char res[100000000];
int main()
{
    int reslen = 0, amount_of_strings;
    char input[100], *last_index = res;
    scanf("%d", &amount_of_strings);

    for (int step = 0; step < amount_of_strings; ++step)
    {
        scanf("%s", input);
        last_index = concat(last_index, input);
    }
    printf("%s", res);
    return 0;
}