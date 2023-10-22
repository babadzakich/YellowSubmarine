#include <stdio.h>

int main()
{
    int amount_of_elements, amount_of_pairs, elements[301][301], first_element, second_element;
    scanf("%d %d", &amount_of_elements, &amount_of_pairs);
    for (int step = 0; step < amount_of_pairs; ++step)
    {
        scanf("%d %d", &first_element, &second_element);
        elements[first_element][second_element] ++;
    }
    int flag = 0, mnogozn = 0, flag2 = 0;

    for (int step = 0; step < amount_of_elements; ++step)
    {
        mnogozn = 0;

        for (int step2 = 0; step2 < amount_of_elements; ++step2)
        {
            mnogozn += elements[step][step2];
            if (mnogozn > 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    
    }

    for (int step = 1; step <= amount_of_elements; ++step)
    {
        for (int step2 = 1; step2 <= amount_of_elements; ++step2)
        {
            flag2 = 0;
            if (elements[step][step2] == 1)
            {
                flag2 = 1;
                break;
            }
        }
        if (!flag2){
            break;
        }
        
    }

    int iject = 0, flag3 = 0;
    for (int step = 0; step < amount_of_elements; ++step)
    {
        iject = 0;
        for (int step2 = 0; step2 < amount_of_elements; ++step2)
        {
            iject += elements[step2][step];
            if (iject > 1)
            {
                flag3 = 1;
                break;
            }
        }
        if (flag3)
        {
            break;
        }
    }

    int flag4 = 0;
    for (int step = 1; step <= amount_of_elements; ++step)
    {
        for (int step2 = 1; step2 <= amount_of_elements; ++step2)
        {
            flag4 = 0;
            if (elements[step2][step] == 1)
            {
                flag4 = 1;
                break;
            }
        }
        if (!flag4){
            break;
        }
        
    }

    if (!flag)
    {
        printf("1 ");
    }
    
    if (flag2)
    {
        printf("2 ");
    }
    
    if (!flag3)
    {
        printf("3 ");
    }

    if (flag4)
    {
        printf("4 ");
    }

    if (!flag3 && flag4)
    {
        printf("5");
    }
    if (flag && !flag2 && flag3 && !flag4)
    {
        printf("0");
    }
    return 0;
}