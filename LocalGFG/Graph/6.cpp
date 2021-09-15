class Solution
{
    public:
    //Function to find the number of islands.
    void DFS(vector<vector<char>> &G, vector<vector<int>> &neigh, int sr, int sc, vector<vector<int>> &vis){
        vis[sr][sc] = 1;
        int cr, cc;
        for(int i = 0; i<neigh.size();i++){
            cr = sr + neigh[i][0];
            cc = sc + neigh[i][1];
            
            if(cr < 0 or cr >= G.size() or cc < 0 or cc >= G[0].size()){
                continue;
            }
            
            if(vis[cr][cc] == 0 and G[cr][cc] == '1'){
                // cout<<"rec:"<<cr<<" "<<cc;
                DFS(G, neigh, cr, cc, vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& G) 
    {
        vector<vector<int>> neigh;
        neigh.push_back({-1,-1});
        neigh.push_back({-1,0});
        neigh.push_back({-1,1});
        neigh.push_back({0,-1});
        neigh.push_back({0,1});
        neigh.push_back({1,-1});
        neigh.push_back({1,0});
        neigh.push_back({1,1});
        
        
        int n = G.size();
        int m = G[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m));
        
        int c = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(vis[i][j] == 0 and G[i][j] == '1'){
                    DFS(G, neigh, i, j, vis);
                    // cout<<i<<"::"<<j<<"\n";
                    c++;
                }
            }
        }
        return c;
    }
};
