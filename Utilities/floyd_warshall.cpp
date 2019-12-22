FOR(i, 0, n)
    FOR(j, 0, n)
    {
        if(graph[i][j] == 0)
            shortest_path[i][j] = 1000000;
        else
            shortest_path[i][j] = graph[i][j];
    }
 
FOR(k, 0, n)
    FOR(i, 0, n)
        FOR(j, 0, n)
            shortest_path[i][j] = min(shortest_path[i][j], (shortest_path[i][k]+shortest_path[k][j]));