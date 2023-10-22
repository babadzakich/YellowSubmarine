#include <stdio.h>

int main()
{
    int strcom = 0, blokcom = 0, slash = 0, zvcom = 0;
    char curr;
    while (1) 
    {
        if ( scanf ("%c", &curr ) != 1)
        {
        break;
        }
        if (curr == '/')
        {
            slash = 1;
        }
        if (slash && (curr != '/' || curr != '*'))
        {
            slash = 0;
        }
        if (curr == '/' && slash && !strcom)
        {
            strcom = 1;
            slash = 0;
        }
        while (strcom)
        {
            if (curr == '\0')
            {
                break;
            }
        }
        if (curr == '*' && slash)
        {
            blokcom = 1;
            slash = 0;
        }
    }
    return 0;
}