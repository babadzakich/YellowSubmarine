#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define hashLimit 614657
struct movie{
    char movie[21];
};

typedef struct dataBase{
    char name[31];
    int birthYear;
    char country[11];
    struct movie* movies;
    int top;
    int size;
}DataBase;



int hash (int hashSum)
{
    return hashSum * 307 % hashLimit;
}

int main(void)
{
    int amountOfTests;
    scanf("%d", &amountOfTests);
    int* keys = (int*)malloc(sizeof(int) * amountOfTests);
    int key = 0;
    DataBase *person = (DataBase*)malloc(sizeof(DataBase) * hashLimit);
    for(int step = 0; step < amountOfTests; step++)
    {
        char symbol;
        int index = 0;
        char name[31];
        int hashSum = 0;
        getchar();
        scanf("%c", &symbol);
        scanf("%c", &symbol);
        while (symbol != '"')
        {
            name[index++] = symbol;
            hashSum += (int)symbol;
            scanf("%c", &symbol);
        }
        //name[index] = '\0';
        hashSum = hash(hashSum);
        strcpy(person[hashSum].name, name);
        person[hashSum].name[index] = '\0';
        getchar();
        scanf("%d", &person[hashSum].birthYear);
        getchar();
        scanf("%c", &symbol);
        scanf("%c", &symbol);
        index = 0;
        while (symbol != '"')
        {
            person[hashSum].country[index++] = symbol;
            scanf("%c", &symbol);
        }
        person[hashSum].country[index] = '\0';
        person[hashSum].size = person[hashSum].top = 0;
        keys[key++] = hashSum;
    }
    //printf("\"%s\" %d \"%s\"\n", person[keys[0]].name, person[keys[0]].birthYear, person[keys[0]].country);
    // printf("\"%s\" %d \"%s\"\n", person[keys[1]].name, person[keys[1]].birthYear, person[keys[1]].country);
    int otherTests;
    scanf("%d", &otherTests);
    for (int step = 0; step < otherTests; step++)
    {
        int hashSum = 0;
        char symbol;
        int index = 0;
        getchar();
        scanf("%c", &symbol);
        scanf("%c", &symbol);
        while (symbol != '"')
        {
            hashSum += (int)symbol;
            scanf("%c", &symbol);
        }
        hashSum = hash(hashSum);
        //printf("%s\n", person[hashSum].name);
        getchar();
        scanf("%c", &symbol);
        scanf("%c", &symbol);
        index = 0;
        if(person[hashSum].size == 0)
        {
            person[hashSum].movies = malloc(sizeof(struct movie));
            person[hashSum].size = 1;
        }
        else if(person[hashSum].size == person[hashSum].top)
        {
            person[hashSum].movies = realloc(person[hashSum].movies, sizeof(struct movie) * person[hashSum].size * 2);
            person[hashSum].size *= 2;
        }
        while (symbol != '"')
        {
            person[hashSum].movies[person[hashSum].top].movie[index++] = symbol;
            //printf("%c", person[hashSum].movies[person[hashSum].top].movie[index-1]);
            scanf("%c", &symbol);
        }
        //printf("\n");
        person[hashSum].movies[person[hashSum].top].movie[index] = '\0';
        person[hashSum].top++;
    }
    for(int step = 0; step < amountOfTests; step++)
    {
        int index = keys[step];
        int film = 0;
        while(film != person[index].top)
        {
            printf("\"%s\" %d \"%s\" \"%s\" \"%s\"\n", person[index].name, person[index].birthYear, person[index].country, person[index].name, person[index].movies[film++].movie);
        }   
    }
    free(person);
    return 0;
}