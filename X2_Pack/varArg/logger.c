#include <stdarg.h>
#include <stdio.h>

static FILE* in = 0;
static int logAmount = 0;

void logSetFile(FILE *file)
{
    if (file) in = file;
    if (file == 0) in = 0;
}

void logPrintf(const char *format, ...)
{
    if (in != 0)
    {
        logAmount++;
        va_list izi;
        va_start(izi, format);
        vfprintf(in, format, izi);
        va_end(izi);
    }
}
int getLogCallsCount()
{
    return logAmount;
}