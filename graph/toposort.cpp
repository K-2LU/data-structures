#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;  // number of vertices
vector <vector <int> > adj;
vector <bool> visited;
vector <int> ans;

void dfs(int v) {
    visited[v] = true;
    for (int u: adj[v])
        if(!visited[u])
            dfs(u);
    ans.push_back(v);
}

void toposort() {
    visited.assign(n, false);
    ans.clear();
    for (int i=0; i<n; i++)
        if(!visited[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
}