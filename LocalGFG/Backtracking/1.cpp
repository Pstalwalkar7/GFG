#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution{
public:
    bool safe_from_attack(vi &cur, int ind, int y_ind){
        int hd;
        int vd;
        for(int i = 0; i<ind;i++){
            if(y_ind == cur[i]) return 0;
            vd = abs(cur[i] - y_ind);
            hd = ind - i;
            if (vd == hd) return 0;
        }
        return 1;
    }
    
    void add_configuration(vvi &ans, vi &cur, int ind, int n){
        if(ind == n) ans.push_back(cur);
        for(int i = 0; i<n;i++){
            if(safe_from_attack(cur, ind, i+1)){
                cur[ind] = i+1;
                add_configuration(ans, cur, ind + 1, n);
            }
        }    
    }
    
    vector<vector<int>> nQueen(int n) {
        vvi ans;
        vi cur(n);
        for(int i = 0;i<n;i++){
            cur[0] = i+1;
            add_configuration(ans, cur, 1, n);
        }  
        return ans;
    }
};
