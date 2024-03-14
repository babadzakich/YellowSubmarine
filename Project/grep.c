#include <stdio.h>
#include<stdlib.h>
#include<string.h>
char buffer[1024];

int main(int argc, char** argv)
{
    if (argc == 1) return 1;
    char* pattern = argv[1];
    char* inputFile = argv[2];
    FILE *in = fopen(inputFile, "r");
    
    int pos = 0, length = strlen(pattern);
    char curr;
    int bufLen = 0;

    while(fscanf(in, "%c", &curr) != EOF)
    {       
        
        buffer[bufLen++] = curr;
        if (curr == '\n')
        {
            for(int step = 0; step < bufLen; step++)
            {
                // printf("%c\n", buffer[step]);
                if(buffer[step] == pattern[pos])
                {
                    // printf("%c\n", pattern[pos]);
                    pos++;
                    if(pos == length)
                    {
                        printf("%s\n", buffer);
                        pos = 0;
                        break;
                    }
                }
                else
                {
                    pos = 0;
                }
                
            }
            memset(buffer, 0, bufLen);
            bufLen = 0;
        }
    }
    for(int step = 0; step < bufLen; step++)
    {
        // printf("%c\n", buffer[step]);
        if(buffer[step] == pattern[pos])
        {
            // printf("%c\n", pattern[pos]);
            pos++;
            if(pos == length)
            {
                printf("%s\n", buffer);
                pos = 0;
                break;
            }
        }
        else
        {
            pos = 0;
        }
        
    }
    return 0;
}