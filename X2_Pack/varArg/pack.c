#include <stdarg.h>
#include <string.h>


int pack(char *buffer, const char *format, ...)
{
    char curr = format[0];
    int numberOfBytes = 0;
    int step = 0;
    va_list pamparam;
    va_start(pamparam, format);
    while(curr != '\0')
    {
        curr = format[step];
        if (curr ==  '%')
        {
            step++;
            continue;
        }

        if (curr == 'd')
        {
            int input = va_arg(pamparam, int);
            if (buffer) *(int*)(buffer+numberOfBytes) = input;
            numberOfBytes += 4;
            step++;
        }
        else if (curr == 'l')
        {
            double input = va_arg(pamparam, double);
            if (buffer) *(double*)(buffer+numberOfBytes) = input;
            numberOfBytes += 8;
            step += 2;
        }
        else if (curr == 's')
        {
            char* input = va_arg(pamparam, char*);
            int len = strlen(input) + 1;
            if (buffer) memcpy(buffer + numberOfBytes, input, len);
            numberOfBytes += len;
            step++;
        }
    }
    va_end(pamparam);
    return numberOfBytes;
}