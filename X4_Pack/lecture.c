int cur;
int c[n];
int id = n-1;
int a[n];
vec R[n];
vec G[n];
char used[n];
void dfs(int u)
{
    if (used[u] == 0)
    {
        used[u] = 1;
        for(int i = 0; i < v[u].size; i++)
        {
            dfs(v[u][i]);
        }
    }
}

int countcc()
{
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            l++;
            dfs(i);
        }
    }
    return l
}

int dfs1 (int u)
{
    used[u] = 1;
    for (int step = 0; step < G[u].size; step++)
    {

    }
}