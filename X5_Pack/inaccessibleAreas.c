    #include <stdio.h>
    #include <stdlib.h>

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int area_length;

    int corr(int x, int y) 
    {
        if (x < 0 || y < 0 || x >= area_length || y >= area_length) return 0;
        return 1;
    } 

    void dfs(char** matrix, int cy, int cx)
    {
        if (matrix[cy][cx] == '*' || matrix[cy][cx] == '#') return;
        matrix[cy][cx] = '#';
        for(int step = 0; step < 4; step++) 
        {
            if(corr(cx + dx[step], cy + dy[step])) 
            {
                dfs(matrix, cy + dy[step], cx + dx[step]);
            }
        } 
    }

    int main(void)
    {
        scanf("%d\n", &area_length);
        char** matrix = (char**)malloc(sizeof(char*) * (area_length));
        for(int step = 0; step < area_length; step++)
        {
            matrix[step] = (char*)malloc(sizeof(char) * (area_length + 2));
            fgets(matrix[step], 10000, stdin);
        }
        int counter = 0;
        
        for(int step = 0; step < area_length; step++)
        {
            if(matrix[0][step] == ' ')
            {
                dfs(matrix, 0, step);
            }
        }

        for(int step = 0; step < area_length; step++)
        {
            for(int step2 = 0; step2 < area_length; step2++)
            {
                if(matrix[step][step2] == ' ')
                {
                    dfs(matrix, step, step2);
                    counter++;
                }
            }
        }
        for(int step = 0; step < area_length; step++) free(matrix[step]);
        free(matrix);
        printf("%d", counter);
        return 0;
    }