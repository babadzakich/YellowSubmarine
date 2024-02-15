#include <stdio.h>
int main()
{
    FILE *in, *out;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    char letter[110];
    int flag = 0, flag2 = 0;
    while(fgets(letter, 110, in)!= NULL)
    {   
        for(int step = 0; step < 110; step++)
        {
            if (letter[step] == '\n' || letter[step] == '\0')
            {
                break;
            }
            if (letter[step] == '\"' && !flag)
            {
                fprintf(out,"[");
                flag = 1;
                continue;
            }
            else if (letter[step] == '\"' && flag)
            {
                fprintf(out,"]\n");
                flag = 0;
                continue;
            }
            if (flag)
            {
                fprintf(out, "%c", letter[step]);
            }
            else
            {
                if (letter[step] == 32 && flag2)
                {
                    flag2 = 0;
                    fprintf(out, "]\n");
                    continue;
                }
                if (letter[step] == 32 && !flag2)
                {
                    continue;
                }
                if (letter[step] != 32 && !flag2)
                {
                    flag2 = 1;
                    fprintf(out, "[%c", letter[step]);
                }
                else
                {
                    fprintf(out, "%c", letter[step]);
                }
            }
        }
    }
    if (flag2 || flag)
    {
        fprintf(out, "]\n");
    }
    fclose(in);
    fclose(out);
    return 0;
}