#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define hashLimit 614657

typedef struct dataBase{
    char name[31];
    int birthYear;
    char country[11];
    struct movie* movies;
    int top;
    int size;
}DataBase;

struct movie{
    char name[31];
    char movie[21];
};

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
            hashSum += printf("\"%s\" %d \"%s\"\n", person[keys[0]].name, person[keys[0]].birthYear, person[keys[0]].country);(int)symbol;
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
    printf("\"%s\" %d \"%s\"\n", person[keys[0]].name, person[keys[0]].birthYear, person[keys[0]].country);
    printf("\"%s\" %d \"%s\"\n", person[keys[1]].name, person[keys[1]].birthYear, person[keys[1]].country);
    return 0;
}