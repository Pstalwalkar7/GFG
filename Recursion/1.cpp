class Solution {
public:

    void DFS(vector<vector<int>> &G, int sr, int sc, vector<pair<int, int>> &neigh, vector<vector<int>> &vis,
    int newColor, int origColor){
        vis[sr][sc] = 1;
        G[sr][sc] = newColor;
        int cr, cc;
        
        for(int i = 0; i<neigh.size();i++){
            cr = sr + neigh[i].first;
            cc = sc + neigh[i].second;
            
            if(cr < 0 or cc < 0 or cr >= G.size() or cc >= G[0].size()){
                continue;
            }
            
            if(vis[cr][cc] == 0 and G[cr][cc] == origColor){
                DFS(G, cr, cc, neigh, vis, newColor, origColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<pair<int,int>> neigh;
        neigh.push_back({1,0});
        neigh.push_back({-1,0});
        neigh.push_back({0,1});
        neigh.push_back({0,-1});
        
        vector<vector<int>> vis(image.size(), vector<int>(image[0].size()));
        DFS(image, sr, sc, neigh, vis, newColor, image[sr][sc]);    
        
        return image;
    }   
};