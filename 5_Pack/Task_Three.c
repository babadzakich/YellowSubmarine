#include <stdio.h>

typedef struct Label_s {
    char name [16]; //имя автора (заканчивается нулём)
    int age ; //возраст автора (сколько лет)
} Label ;

typedef struct NameStats_s {
    int cntTotal ; //сколько всего подписей
    int cntLong ; //сколько подписей с именами длиннее 10 букв
} NameStats ;

typedef struct AgeStats_s {
    int cntTotal ; //сколько всего подписей
    int cntAdults ; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids ; //сколько подписей детей (меньше 14 лет)
} AgeStats ;
void calcStats ( const Label * array , int cnt , NameStats * oNames , AgeStats * oAges )
{
    for(int step = 0; step < cnt; ++step)
    {
        int step2 = 0, nameLength = 0;

        while (array[step].name[step2] != 0)
        {
            nameLength ++;
            step2++;
            if (nameLength > 10)
            {
                oNames->cntLong ++;
                break;
            }
        }
        if (array[step].age >= 18)
        {
            oAges->cntAdults ++;
        }
        else if (array[step].age < 14)
        {
            oAges->cntKids ++;
        }
    }
    printf("names: total = %d\n", oNames->cntTotal);
    printf("names: long = %d\n", oNames->cntLong);
    printf("ages: total = %d\n", oAges->cntTotal);
    printf("ages: adult = %d\n", oAges->cntAdults);
    printf("ages: kid = %d", oAges->cntKids);
}
int main()
{
    AgeStats agestat;
    NameStats namestat;
    Label persons[1001];
    int amount_of_names, step2 = 0, step3 = 0;
    char Name[4];
    scanf("%d", &amount_of_names);
    agestat.cntTotal = amount_of_names;
    agestat.cntAdults = 0;
    agestat.cntKids = 0;
    namestat.cntTotal = amount_of_names;
    namestat.cntLong = 0;
    for (int step = 0; step < amount_of_names; ++step)
    {
        scanf("%16s %d %s", persons[step].name, &persons[step].age, Name);
    }
    calcStats (persons, amount_of_names, &namestat, &agestat);
    return 0;
}