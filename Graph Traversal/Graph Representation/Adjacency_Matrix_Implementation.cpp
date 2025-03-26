#include<bits/stdc++.h>
using namespace std;
int main(){
    
// input Node and edge

int n,e;
cin>>n>>e;

//matrix row for Node And coloumn for Node

int adj_marix [n][n];

//first initial value set (0) using loop


// for(int i=0; i<n; i++){
//     for(int j=0; j<n; j++){
//         adj_marix[i][j]=0;
//     }
// }

//Another approach for set initial value (0) using memset function

//memset( কাকে রাখতে চাই বা কার মেমোরি রাখতে চাই ,তার মেমোরিতে কি রাখতে চাই ,কতগুলো value কে করতে চাই )

memset(adj_marix,0,sizeof(adj_marix));

//Set diagonal value in 1

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(i==j){
            adj_marix[i][j]=1;
        }
    }
}

//set conncetion edge

for(int i=0; i<e; i++){
    int a,b;
    cin>>a>>b;
    adj_marix[a][b]=1;
    adj_marix[b][a]=1;// if graph is directed graph then this line could not be written
}

//print adjacency print

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
       cout<<adj_marix[i][j]<<" ";
    }
    cout<<endl;
}
    return 0;
}