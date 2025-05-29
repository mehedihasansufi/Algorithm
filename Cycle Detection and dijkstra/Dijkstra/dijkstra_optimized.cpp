#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<pair<int,int>> adj_list[100];
int dis[100];
void dijkstra(int src){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src]=0;

    while(!pq.empty()){
        pair<int,int> par=pq.top();
        pq.pop();
        int pare_node=par.second;
        int pare_dis=par.first;

        for(pair<int,int> child : adj_list[pare_node]){
            int child_node=child.first;
            int child_dis=child.second;

            if(pare_dis+child_dis<dis[child_node] ){
                dis[child_node]=pare_dis+child_dis;
                pq.push({dis[child_node],child_node});
            }
        }
    }

}
int main (){

    int n,e;
    cin>>n>>e;

    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    for(int i=0; i<n; i++){
        dis[i]=INT_MAX;
    }
    dijkstra(0);

    for(int i=0; i<n; i++){
        cout<<i<<" -> "<<dis[i]<<endl;
    }
}


// input 

// 5 6
// 0 1 4
// 0 2 1
// 1 3 1
// 2 1 2
// 2 3 5
// 3 4 3

// output
// 0 -> 0
// 1 -> 3
// 2 -> 1
// 3 -> 4
// 4 -> 7