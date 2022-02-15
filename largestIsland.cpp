#include<iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n, int i, int j) {
    visited[i][j] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    int cs = 1;

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];

        if ( (ni >= 0 && ni < m) && (nj >= 0 && nj < n) && (!visited[ni][nj]) && (grid[ni][nj] == 1) ) {
            cs += dfs(grid, visited, m, n, ni, nj);
        }
    }

    return cs;
}

int largest_island(vector<vector<int>> &grid) {
    int largest = INT_MIN;

    int currentSize = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited (m, vector<bool> (n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && (grid[i][j] == 1)) {
                currentSize = dfs(grid, visited, m, n, i, j);
                if (currentSize > largest) {
                    largest = currentSize;
                }
            }
        }
    }
    return largest;
}


int main(){
    vector<vector<int> > grid = {
                            {1, 0, 0, 1, 0},
                            {1, 0, 1, 0, 0},
                            {0, 0, 1, 0, 1},
                            {1, 0, 1, 1, 1},
                            {1, 0, 1, 1, 0}
                            };
    // int m = grid.size();
    // int n = grid[0].size();
    // vector<vector<bool>> visited (m, vector<bool> (n, false));
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << i << " " << j << ": ";
    //         cout << dfs(grid, visited, m, n, 0, 0) << endl;
    //     }
    // }
    cout<< largest_island(grid) <<endl;


    return 0;
}
