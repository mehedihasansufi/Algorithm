#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
int parent[100];
bool cycle=false;
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=true;
    while(!q.empty()){
        int par=q.front();
        q.pop();
        
        for(int value : adj_list[par]){

            if(vis[value] && parent[par]!=value){
                cycle=true;

            }
            if(!vis[value]){
                q.push(value);
                vis[value]=true;
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
memset(parent,-1,sizeof(parent));
for(int i=0; i<n; i++){
    if(!vis[i]){
        bfs(i);
    }
}
if(cycle)
  cout<<"cycle detect";
  else
  cout<<"no Cycle";
    return 0;
}


// input here 

// 5 5
// 0 1
// 1 2
// 2 3
// 3 4
// 4 1
// output 
// cycle detect


// input here 

// 5 4
// 0 1
// 1 2
// 2 3
// 3 4

// output 
// no Cycle