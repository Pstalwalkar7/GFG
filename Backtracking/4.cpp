#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;

public:
    void findWord(vvc &board, vvi &vis, vvi &neigh, string &word, int ind, bool &found, int p_x, int p_y, int& m, int& n){
        if (ind == word.size()){
            found = 1;
            return;
        }
        if(ind == 0){
            for(int i = 0;i<m;i++){
                for(int j =0; j<n;j++){
                    if(board[i][j] == word[ind]){
                        vis[i][j] = 1;
                        findWord(board, vis, neigh, word, ind + 1, found, i, j, m, n);
                        vis[i][j] = 0; 
                    }
                }
            }
        }
        else{
            int x,y;
            for(auto i: neigh){
                x = p_x + i[0];
                y = p_y + i[1];
                if(x >= m or y >= n or x <0 or y<0) continue;
                if(vis[x][y] == 0 and board[x][y] == word[ind]){
                    vis[x][y] = 1;
                    // cout<<"Nonzero: ("<<x<<","<<y<<")::"<<word<<"::"<<ind<<"\n";
                    findWord(board, vis, neigh, word, ind + 1, found, x, y, m, n);
                    vis[x][y] = 0;
                }
            }
        }
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    bool found;
	    int m = board.size();
	    int n = board[0].size();
	    int k = dictionary.size();
	    vvi vis(m, vi(n));
	    vvi neigh = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1, -1}, {1,0}, {1,1}};
	    vs ans;
	    string word;
	    for(int i =0; i<k;i++){
	        found = 0;
	        word = dictionary[i];
	        findWord(board, vis, neigh, word, 0, found, -1,-1, m, n);
	        if(found == 1) ans.push_back(word);
	    }
	    return ans;
	}
};