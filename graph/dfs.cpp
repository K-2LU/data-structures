#include <iostream>
#include <vector>
using namespace std;

vector <int> v[10];
bool visited[10];

void dfs_rec(int s)  {
    visited[s] = true;
    for (int i = 0; i < v[s].size(); i++)
        if(!visited[v[s][i]])
            dfs_rec(v[s][i]);
}