typedef vector<int> vi;
typedef vector<vi> vvi
;
class Solution{
public:
    
    void BFS(vvi &G, vi &dist, int src){
        vi neigh = {1, 2, 3, 4, 5, 6};
        queue<int> Q;
        int n = G.size();
        vi vis(n);
        
        dist[src] = 0;
        Q.push(src);
        
        while(!Q.empty()){
            
            int x = Q.front();
            // cout<<x<<"\n";
            Q.pop();
            for(auto i: G[x]){
                dist[i] = dist[x];
                if(vis[i] == 0){
                    vis[i] = 1;
                    Q.push(i);
                }
            }
            for(int i = 0; i<neigh.size(); i++){
                int loc = x + neigh[i];
                int nd = dist[x] + 1;
                if(loc > 30) continue;
                if(vis[loc] == 0){
                    vis[loc] = 1;
                    Q.push(loc);
                }
                dist[loc] = min(dist[loc],nd);
            }
        }
    }

    int minThrow(int n, int arr[]){
        vvi G(31);
        for(int i = 0; i<n;i++){
            auto src = arr[2*i];
            auto dest = arr[2*i + 1];
            G[src].push_back(dest);
        }
        vi dist(31, INT_MAX);
        BFS(G, dist, 1);
        return dist[30];
    }
};