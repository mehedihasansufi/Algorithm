#include<bits/stdc++.h>
using namespace std;
int row,col;
char grid[100][100];
bool vis[100][100];
vector<pair<int,int>> val={{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j){
    if(i<0 || i>=row || j<0 || j>=col)
     return false;
     return true;
}
void dfs(int rowIndex,int colIndex){
    cout<<rowIndex<<" "<<colIndex<<endl;
    vis[rowIndex][colIndex]=true;
    for(int i=0; i<4; i++){
        int ri=rowIndex+val[i].first;
        int ci=colIndex+val[i].second;
       if(valid(ri,ci)==true && vis[ri][ci]==false)
         dfs(ri,ci);
    }
}
int main (){


cin>>row>>col;
for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
        cin>>grid[i][j];
    }
}
int rowIndex,colIndex;
cin>>rowIndex>>colIndex;
memset(vis,false,sizeof(vis));
dfs(rowIndex,colIndex);
    return 0;
}