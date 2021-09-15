#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> neigh = {{-1,0}, {0,-1}, {0,1}, {1,0}};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>> Q;
        // set<vector<int>> S;
        
        dist[0][0] = grid[0][0];
        Q.push({-grid[0][0], 0, 0});
        // S.insert({grid[0][0], 0, 0});
        
        int wt, x, y, nx, ny;
        
        while(!Q.empty()){
            auto A = Q.top();
            Q.pop();
            // auto A = *S.begin();
            // S.erase(S.begin());
            // wt = A[0];
            
            wt = -A[0];
            x = A[1];
            y = A[2];
            
            for(auto i : neigh){
                nx = x + i.first;
                ny = y + i.second;
                
                if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                
                if (dist[nx][ny] > dist[x][y] + grid[nx][ny]){
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    Q.push({-grid[nx][ny], nx, ny});
                    // S.insert({grid[nx][ny], nx, ny});
                }
            }
        }
        
        // for(int i = 0; i<n;i++){
        //     for(int j = 0; j<m;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dist[n-1][m-1];
    }
};