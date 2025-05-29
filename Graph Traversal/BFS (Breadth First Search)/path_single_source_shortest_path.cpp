#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
int level[100];
int parent[100];
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    level[src]=0;
    while(!q.empty()){
        int par=q.front();
        q.pop();
        for(int value: adj_list[par]){
            if(!vis[value]){
                q.push(value);
                vis[value]=true;
                level[value]=level[par]+1;
                parent[value]=par;
            }
        }
    }

}
int main (){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));

    int destination,source;
    cin>>source>>destination;
    bfs(source);

    vector<int>path;
    int node=destination;
    while(node!=-1){
    
        path.push_back(node);
        node=parent[node];
    }

    reverse(path.begin(),path.end());

    for(int value: path){
        cout<<value<<" ";
    }

    
}