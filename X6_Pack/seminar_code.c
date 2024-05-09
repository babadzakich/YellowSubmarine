#include <stdio.h>
#include<stdlib.h>
typedef struct 
{
    size_t cap;
    size_t top;
    int to[1000];
}Vector;

int N;
int stepper = 1;
Vector t[100000];
int mt[100000];
int visited[100000];
int cnt = 0;
int dfs(int u)
{
    if (visited[u] == stepper) return 0;
    visited[u] = stepper;

    for(int step = 0; step < t[u].top; step++)
    {
        int to = t[u].to[step];
        if(mt[to] == -1 || dfs(mt[to]))
        {
            mt[to] = u;
            return 1;
        }
    }
    return 0;
}

void matching()
{
    memset(mt, -1, sizeof(mt));
    for(int step = 1; step <= N; step++)
    {
        stepper ++;
        cnt += dfs(step);
    }
}