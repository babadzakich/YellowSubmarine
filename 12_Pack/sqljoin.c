#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dataBase{
    char name[31];
    int birthYear;
    char country[11];
}DataBase;

typedef struct movie{
    char name[31];
    char movie[21];
}Movie;

int main(void)
{
    int amountOfTests;
    scanf("%d", &amountOfTests);
    DataBase *person = (DataBase*)malloc(sizeof(DataBase) * amountOfTests);
    for(int step = 0; step < amountOfTests; step++)
    {
        char symbol;
        int index = 0;
        getchar();
        scanf("%c", &symbol);
        scanf("%c", &symbol);
        while (symbol != '"')
        {
            person[step].name[index++] = symbol;
            scanf("%c", &symbol);
        }
        person[step].name[index] = '\0';
        getchar();
        scanf("%d", &person[step].birthYear);
        getchar();
        scanf("%c", &symbol);
        scanf("%c", &symbol);
        index = 0;
        while (symbol != '"')
        {
            person[step].country[index++] = symbol;
            scanf("%c", &symbol);
        }
        person[step].country[index] = '\0';
    }
    // printf("\"%s\" %d \"%s\"\n", person[0].name, person[0].birthYear, person[0].country);
    // printf("\"%s\" %d \"%s\"\n", person[1].name, person[1].birthYear, person[1].country);
    int otherTests;
    scanf("%d", &otherTests);
    Movie *films = (Movie*)malloc(sizeof(Movie) * otherTests);
    for (int step = 0; step < otherTests; step++)
    {
        char symbol;
        int index = 0;
        getchar();
        scanf("%c", &symbol);
        scanf("%c", &symbol);
        while (symbol != '"')
        {
            films[step].name[index++] = symbol;
            scanf("%c", &symbol);
        }
        films[step].name[index] = '\0';
        getchar();
        scanf("%c", &symbol);
        scanf("%c", &symbol);
        index = 0;
        while (symbol != '"')
        {
            films[step].movie[index++] = symbol;
            scanf("%c", &symbol);
        }
        films[step].movie[index] = '\0';
    }
    for(int step = 0; step < amountOfTests; step++)
    {
        for(int step2 = 0; step2 < otherTests; step2++)
        {
            if(strcmp(person[step].name, films[step2].name) == 0)
            {
                printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n", person[step].name, person[step].birthYear, person[step].country, films[step2].name, films[step2].movie);
            }
        }
    }
    free(person);
    free(films);
    return 0;
}