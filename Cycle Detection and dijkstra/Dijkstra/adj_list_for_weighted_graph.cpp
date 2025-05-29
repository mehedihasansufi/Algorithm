#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> adj_list[100];
int main()
{

    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> value : adj_list[i])
        {
            cout << "(" << value.first << "," << value.second << ") ";
        }
        cout << endl;
    }

    return 0;
}



// input here 

// 5 4
// 0 1 5
// 0 2 6
// 2 3 8
// 1 4 9



// output here 

// 0 -> (1,5) (2,6) 
// 1 -> (0,5) (4,9)
// 2 -> (0,6) (3,8)
// 3 -> (2,8)
// 4 -> (1,9)