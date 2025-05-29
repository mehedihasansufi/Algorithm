#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int row, col;

char grid[100][100];
bool vis[100][100];
int level[100][100];
vector<pair<int, int>> move_ment = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};


bool valid(int check_row, int check_col)
{
    if (check_row < 0 || check_row >= row || check_col < 0 || check_col >= col)
        return false;

    return true;
}
void bfs(int src_row, int src_col)
{

    queue<pair<int, int>> q;
    q.push({src_row, src_col});
    vis[src_row][src_col] = true;
    level[src_row][src_col]=0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        //cout << par.first << " " << par.second << endl;

        for (pair<int, int> child : move_ment)
        {
            int child_row = par.first + child.first;
            int child_col = par.second + child.second;

            if (!vis[child_row][child_col] && valid(child_row, child_col) && grid[child_row][child_col]!='#')
            {

                q.push({child_row, child_col});
                vis[child_row][child_col]=true;
                level[child_row][child_col]=level[par.first][par.second]+1;
            }
        }
    }
}
int main()
{

    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
        }
    }

    int src_row, src_col,dis_row,dis_col;
    cin >> src_row >> src_col>>dis_row>>dis_col;
    memset(vis, false, sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(src_row, src_col);
    cout<<level[dis_row][dis_col];
}