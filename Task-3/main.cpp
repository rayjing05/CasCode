#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int N, M, X, Y;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u)
{
    vis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    cin >> N >> M >> X >> Y;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int num_people = 0;
    long long total_charges = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            num_people++;
            total_charges += X + Y * (int)adj[i].size();
        }
    }
    if (num_people == 1)
    {
        total_charges -= X;
    }
    else
    {
        total_charges += X * (num_people - 2);
    }
    cout << total_charges << endl;
    return 0;
}
