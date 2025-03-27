#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[100];

void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=true;
    
    while(!q.empty()){
        int parent=q.front();
        q.pop();

        for(int value: adj_list[parent]){
            if(vis[value]==false){
                q.push(value);
                vis[value]=true;
                
            }
        }
    }
}
int main(){

    int n,e; cin>>n>>e;

    while(e--){
        int a,b; cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int source,destination; cin>>source>>destination;
    memset(vis,false,sizeof(vis));
   
    bfs(source);
   if(vis[destination]){
    cout<<"Yes";
   }else{
    cout<<"No";
   }
    return 0;
}