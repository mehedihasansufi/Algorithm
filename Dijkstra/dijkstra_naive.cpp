#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > adj_list[100];
int dis[100];


void dijkstra (int src){
    queue<pair<int,int>>q;
    q.push({src,0});
    dis[src]=0;

    while(!q.empty()){

        pair<int,int> par=q.front();
        q.pop();
        int parent_node=par.first;
        int parent_dis=par.second;
        for(pair<int,int>child: adj_list[parent_node]){
            int child_node=child.first;
            int child_dis=child.second;
            if(parent_dis+child_dis<dis[child_node]){
                dis[child_node]=parent_dis+child_dis;
                q.push({child_node,dis[child_node]});
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

    for(int i=1; i<=n; i++){
        dis[i]=INT_MAX;
    }
    dijkstra(1);


   for(int i=1;i<=n;i++)
        cout << i << " -> " << dis[i] << endl;
        return 0;
}


// input here
// 6 8
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 5 4 2
// 5 6 5
// 4 6 1


//output here

// 1 -> 0
// 2 -> 2
// 3 -> 3
// 4 -> 8
// 5 -> 6
// 6 -> 9
