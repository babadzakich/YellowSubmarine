#include <string.h>



char text[100000];
int pos = 0;                                   //текущая позиция в тексте

char* token;                                           //текущий токен
char* readToken(int* pos, char* token, char* text)
{
    while (isspace(text[*pos]))
    {
        *pos++;                                  //(см. функцию isspace из стандартной библиотеки)
    }
    if (text[*pos] == '\0')
    {                          //если символ нулевой, то это конец текста
        return token = "";                       //возвращаем токен [eof]
    }
    if (text[*pos] == '+' || text[*pos] == '-' || text[*pos] == '*' || text[*pos] == '/' || text[*pos] == '(' || text[*pos] == ')')  //это простой односимвольный токен
    {
        return token = text[*pos++];              //копируем его в буфер token и возвращаем
    }
    int left = *pos;                                  //остался один случай: целое число
    while (isdigit(text[*pos])) *pos++;
    memcpy(token, text+left, sizeof(char) * (*pos-left));  
    return token;              //копируем отрезок в буфер token и возвращаем
}

char* peekToken(int* pos, char* token, char* text)
{
    int oldPos = *pos;
    token = readToken(pos, token, text);
    *pos = oldPos;
    return token;
}

double parseExpr(int* pos, char* token, char* text)
{
    double res = parseMonom();
    while (peekToken(pos, token, text)[0] == '+' || peekToken(pos, token, text)[0] == '-')
    {
        char* oper = readToken(pos, token, text);
        double add = parseMonom();
    }
}