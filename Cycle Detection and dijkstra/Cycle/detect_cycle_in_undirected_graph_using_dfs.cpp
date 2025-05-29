#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
int parent[100];
bool cycle=false;
void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_list[src])
    {

        if (vis[child] && parent[src]!=child){
            cycle=true;

        }
            if (!vis[child])
            {
                parent[child] = src;
                dfs(child);
            }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < n; i++)
    {

        if (!vis[i])
        {
            dfs(i);
        }
    }
   if(cycle){
    cout<<"cycle detect";
   }else{
    cout<<"no cycle";
   }
    return 0;
}



// input here 

// 5 5
// 0 1
// 1 2
// 2 3
// 3 4
// 4 1


// output here
// cycle detect

// input here 

// 5 4
// 0 1
// 1 2
// 2 3
// 3 4

// output 

// no cycle
