#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis [100];
void dfs(int source){
//base case

cout<<source<<" ";
vis[source]=true;
for(int val: adj_list[source]){
    if(vis[val]!=true){
        dfs(val);
    }
}

}
int main (){

    int node,edge;
    cin>>node>>edge;

    while(edge--){
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
int src;
cin>>src;
memset(vis,false,sizeof(vis));
dfs(src);
    return 0;
}