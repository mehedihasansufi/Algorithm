#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
bool pathvis[100];
bool cycle=false;
void dfs(int src){
    vis[src]=true;
    pathvis[src]=true;

    for(int value : adj_list[src]){

        if(vis[value]  && pathvis[value]){
            cycle=true;
        }
        if(!vis[value]){
            dfs(value);
        }
    }

    pathvis[src]=false;

}
int main (){

    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
    }

    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));
    for(int i=0; i<n; i++){
        if(!vis[i]){
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


// input 

// 4 4
// 0 1
// 1 2
// 2 3
// 3 1
// output
// cycle detect


// input 

// 4 3
// 0 1
// 1 2
// 2 3
// output
// no cycle