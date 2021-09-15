typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution{
    public:
    
    int diff(string S1, string S2){
        int n = S1.size();
        int m = S2.size();
        for(int i =0; i<n and i<m;i++){
            if(S1[i] != S2[i]) return i;
        }
        return -1;
    }
    
    vi topological_sort(vvi &G){
        int n = G.size();
        vi indeg(n);
        for(int i = 0; i<n;i++){
            for(auto x: G[i]){
                indeg[x]++;
            }
        }
        queue<int> Q;
        vi ret;
        for(int i = 0; i<n;i++){
            if(indeg[i] == 0) Q.push(i);
        }
        while(!Q.empty()){
            auto x = Q.front();
            Q.pop();
            ret.push_back(x);
            for(auto i: G[x]){
                indeg[i]--;
                if(indeg[i] == 0) Q.push(i);
            }
        }
        return ret;
    }
    
    string findOrder(string dict[], int n, int k) {
        vvi G(k);
        int diff_index;
        for(int i = 0; i+1<n;i++){
            diff_index = diff(dict[i], dict[i+1]);
            if(diff_index == -1) continue;
            auto s = dict[i][diff_index] - 'a';
            auto d = dict[i+1][diff_index] - 'a';
            G[s].push_back(d);
        }
        vi order;
        order = topological_sort(G);
        string ans;
        for(int i = 0; i<k;i++){
            ans += ('a' + order[i]);
        }
        return ans;
    }
};