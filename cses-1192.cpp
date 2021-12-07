#include <bits/stdc++.h>
using namespace std;

int xi[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int yi[] = {1, 1, 1, 0, 0, -1, -1, -1};

int main()	{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	char a[n][m];
	bool visited[n][m];
	int level[n][m];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			visited[i][j] = false, level[i][j]=0;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	int bfs = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if(a[i][j]=='.' && visited[i][j]==false)	{
				++bfs;
				queue < pair <int, int> > q;
				q.push(make_pair(i, j));
				visited[i][j];
				level[i][j] = 1;

				while(!q.empty())	{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					
					for (int p = 0; p < 8; p++)	{
						int u = x + xi[i];
						int v = y + yi[i];

						if(u>=n || u<0)	continue;
						if(v>=m || v<0)	continue;
						
						if(a[u][v]=='.' && visited[u][v]==false)	{
							q.push(make_pair(u, v));
							visited[u][v] = true;
							level[u][v] = level[x][y] + 1;
						}
					}
				}
			}
	cout << bfs << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
				cout << level[i][j];
		cout << endl;
	}
}