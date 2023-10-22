#include <stdio.h>

int main()
{
    int amount_of_elements, amount_of_pairs, elements[301][301] = { 0 }, first_element, second_element;
    scanf("%d %d", &amount_of_elements, &amount_of_pairs);
    for (int step = 0; step < amount_of_pairs; ++step)
    {
        scanf("%d %d", &first_element, &second_element);
        elements[first_element][second_element] ++;
    }
    int flag = 1, flag2 = 1, flag3 = 1, flag4 = 1, flag5;

    for (int step = 1; step <= amount_of_elements; step++)
    {
        int mnogozn = 0;

        for (int step2 = 1; step2 <= amount_of_elements; ++step2)
        {
            mnogozn += elements[step][step2];// trebuetsa upgrade
        }
        if (flag && mnogozn > 1)
        {
            flag = 0;
        }
        if (flag2 && mnogozn == 0)
        {
            flag2 = 0;
        }
    
    }
    for (int step = 1; step <= amount_of_elements; ++step)
    {
        int inject = 0;
        for (int step2 = 1; step2 <= amount_of_elements; ++step2)
        {
            inject += elements[step2][step];
        }
        if (flag3 && inject > 1)
        {
            flag3 = 0;
        }
        if (flag4 && inject == 0){
            flag4 = 0;
        }
        
    }
    if (!flag) flag2 = 0;
    if (!flag3) flag4 = 0;
    flag5 = flag3 & flag4;
    if ( flag + flag2 + flag3 + flag4 == 0)
    {
        printf("0");
    }
    else
    {
    if (flag) printf("1 ");
    
    if (flag2) printf("2 ");
        
    if (flag3) printf("3 ");

    if (flag4) printf("4 ");

    if (flag5) printf("5");
    }
    return 0;
}