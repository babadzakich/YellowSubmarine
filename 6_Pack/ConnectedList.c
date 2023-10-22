#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int next;
    double value;
} Node;

int main ()
{
    
    int amount_of_nodes, firstNode, lastNode;
    scanf("%d %d", &amount_of_nodes, &firstNode);
    Node array[amount_of_nodes];
    for(int step = 0; step < amount_of_nodes; ++step)
    {
        scanf("%lf %d", &array[step].value, &array[step].next);
    }
    for (int step = firstNode; array[step].next >= 0; step = array[step].next)
    {
        printf("%0.3lf\n", array[step].value);
        lastNode = array[step].next;
    }
    printf("%0.3lf\n", array[lastNode].value);
    return 0;
}