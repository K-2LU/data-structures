#include <iostream>
#include <queue>
#include <vector>

std::vector <int> v[10];
bool visited[10];
int level[10];

void bfs(int source)    {
    std::queue <int> q;
    q.push(source);
    level[source] = 1;

    while (!q.empty())  {
        int w = q.front();
        q.pop();

        for (int i = 0; i < v[w].size(); i++)
            if(visited[v[w][i]] == false)   {
                level[v[w][i]] = level[w] + 1;
                q.push(v[w][i]);
                visited[v[w][i]] = true;
            }       
    }    
}