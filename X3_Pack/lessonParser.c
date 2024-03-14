#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int end = 0;
char lastchar = '\0';
typedef enum TokenType{TOKEN_ADD = 0, TOKEN_SUB = 1, TOKEN_MUL = 2, TOKEN_DIV = 3, OPEN_BB = 4, CLOSED_BB = 5, Const = 6, Token_EOF = 7}TokenType;
double add();
typedef struct Token
{
    TokenType type;
    double value;
}Token;

typedef struct Scaner
{
    char* str;
    int len; 
    int cur;
}Scaner;

Token currentToken;


Token advance()
{
    if (end)
    {
        currentToken.type = Token_EOF;
        return currentToken;
    }
    
    char c;
    if (lastchar == '\0') {
        scanf("%c", &c);
    } else {
        c = lastchar;
        lastchar = '\0';
    }

    while (isspace(c))
    {
        scanf("%c", &c);
        if (c == '\0' || c == '\n')
        {
            currentToken.type = Token_EOF;
            return currentToken;
        }
    }

    switch (c)
    {
    case '+':
        currentToken.type = TOKEN_ADD;
        break;
    case '-':
        currentToken.type = TOKEN_SUB;
        break;
    case '*':
        currentToken.type = TOKEN_MUL;
        break;
    case '/':
        currentToken.type = TOKEN_DIV;
        break;
    case '(':
        currentToken.type = OPEN_BB;
        break;
    case ')':
        currentToken.type = CLOSED_BB;
        break;    
    default:
        currentToken.type = Const;
        currentToken.value = 0;
        while (isdigit(c))
        {
            currentToken.value *= 10;
            currentToken.value += c - '0';
            scanf("%c", &c);
        } 

        lastchar = c;
        if (lastchar == '\0' || lastchar == '\n')end = 1;
    break;
    }
}



double grouping() 
{
    advance();
    double res = add();
    advance();

    return res;
}

double constant() 
{
    if (currentToken.type == Const) 
    {
        double v = currentToken.value;
        advance();
        return v;
    }
    return grouping();
}

double unary() 
{
    if (currentToken.type == TOKEN_SUB) 
    {
        advance();
        return -constant();
    }

    return constant();
}


double mul()
{
    double val = unary();
    while(1)
    {
        switch (currentToken.type)
        {
        case TOKEN_MUL:
        {
            advance();
            val *= unary();
            break;
        }
        case TOKEN_DIV:
        {
            advance();
            val /= unary();
            break;
        }
        default:
        {
            return val;
            break;
        }
        }
    }
    
}


double add()
{
    double val = mul();
    while(1)
    {
        switch (currentToken.type) 
        {
            case TOKEN_ADD:
            {
                advance();
                val += mul();
                break;
            }

            case TOKEN_SUB:
            {
                advance();
                val -= mul();
                break;
            }

            default: 
            {
                return val;
                break;
            }
        }
    }
}


int main()
{
    advance();
    printf("%0.15lf", add());
    return 0;
}