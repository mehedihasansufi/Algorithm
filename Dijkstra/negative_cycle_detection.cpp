#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> > adj_list[100];

void negative(int n){
     for(int i=0;i<n; i++){

        for(pair<int,int> child: adj_list[i]){
           if(child.second<0){
            cout<<"YES";
           return;
           }

        }
    }
}
int main() {

    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
         adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
       
    }

   negative(n);
    
    return 0;
}





//input here


// 4 5
// 1 2 3
// 1 4 2
// 4 3 3
// 3 2 -10
// 2 4 5