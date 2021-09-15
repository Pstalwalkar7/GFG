class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0) return -1;
        vector<vector<int>> D(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m));
        vector<pair<int,int>> neigh = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        queue<pair<int,int>> Q;
        Q.push({0,0});
        D[0][0] = 0;
        vis[0][0] = 1;
        int x, y, nx, ny;
        
        while(!Q.empty()){
            auto p = Q.front();
            x = p.first;
            y = p.second;
            for (auto i: neigh){
                nx = x + i.first;
                ny = y + i.second;
                if(nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
                if(A[nx][ny] == 1 and vis[nx][ny] == 0){
                    D[nx][ny] = D[x][y] + 1;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            Q.pop();
        }
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(D[i][j] == INT_MAX) D[i][j] = -1;
                // cout<<D[i][j]<<" ";
            }
            // cout<<"\n";
        }
        return D[X][Y];
    }
};