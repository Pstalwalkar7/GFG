class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n = grid.size();
        int m = grid[0].size();
        int sx, sy, dx, dy;
        
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
                if(grid[i][j] == 2){
                    dx = i;
                    dy = j;
                }
            }
        }
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(m));
        vector<pair<int,int>> neigh = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        queue<pair<int,int>> Q;
        vis[sx][sy] = 0;
        dist[sx][sy] = 0;
        Q.push({sx,sy});
        
        int x,y, nx,ny;
        
        while(!Q.empty()){
            auto t = Q.front();
            x = t.first;
            y = t.second;
            for(auto i: neigh){
                nx = x + i.first;
                ny = y + i.second;
                if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                if(vis[nx][ny] == 0 and grid[nx][ny] != 0){
                    dist[nx][ny] = dist[x][y] + 1;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            Q.pop();
        }
        
        // for(int i = 0; i<n;i++){
        //     for(int j = 0; j<m;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        if(dist[dx][dy] == INT_MAX) return 0;
        return 1;
    }
};