#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

class Solution{
    public:
    
    void traverse(vs &Paths, string &current_path, vvi &m, vvi &vis, vvi &neigh, int s_x, int s_y, int n){
        if(s_x == n-1 and s_y == n-1){
            Paths.push_back(current_path);
            return;
        }
        int n_x, n_y;
        string step;
        for(auto i: neigh){
            if(i[0] == 1) step = "D";
            else if(i[0] == -1) step = "U";
            else if(i[1] == 1) step = "R";
            else if(i[1] == -1) step = "L";
            n_x = s_x + i[0];
            n_y = s_y + i[1];
            if(n_x >= n or n_y>=n or n_x < 0 or n_y < 0) continue;
            if(vis[n_x][n_y] == 0 and m[n_x][n_y]){
                vis[n_x][n_y] = 1;
                string S = current_path + step;
                traverse(Paths, S, m, vis, neigh, n_x, n_y, n);
                vis[n_x][n_y] = 0;
            }
        }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vs Paths;
        vvi vis(n, vi(n));
        vvi neigh = {{0,1}, {1,0}, {-1, 0}, {0,-1}};
        string S = "";
        
        if(m[0][0] == 0) return {"-1"};
        
        vis[0][0] = 1;
        traverse(Paths, S, m, vis, neigh, 0, 0, n);
        
        if(Paths.empty()) return {"-1"};
        
        sort(Paths.begin(), Paths.end());
        return Paths;
    }
};