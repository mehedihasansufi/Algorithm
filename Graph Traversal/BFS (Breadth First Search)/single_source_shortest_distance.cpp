#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[1000];
bool vis[1000];
int level[1000];
void bfs(int source){
    queue<int>q;
    q.push(source);
    level[source]=0;
    vis[source]=true;
    while(!q.empty()){
        int parent=q.front();
        q.pop();

        for(int value: adj_list[parent]){
            if(vis[value]==false){
                q.push(value);
                vis[value]=true;
                level[value]=level[parent]+1;
            }
        }
    }

}
int main(){
    int n,e;
    cin>>n>>e;
    
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }
    int source, destination;
    cin>>source>>destination;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(source);
    cout<<level[destination];
    return 0 ;
}