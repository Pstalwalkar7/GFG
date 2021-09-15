class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> G[], int s){
        // DO a BFS without vis, where the Q is not FIFO, it is Priority queue. keep distances in a separate array.
        
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        vector<int> dist(V, INT_MAX);
        // idea of visited array fails for some reason. WHY???
        
        Q.push({0,s});
        dist[s] = 0;
        
        pii src_pair;
        int d;
        
        while(!Q.empty()){
            src_pair = Q.top();
            d = src_pair.first;
            s = src_pair.second;
            Q.pop();
            for(auto i: G[s]){
                auto node = i[0];
                auto wt = i[1];
                if (dist[node] > dist[s] + wt){
                    dist[node] = dist[s] + wt;
                    Q.push({wt, node});
                }
            }
        }
        return dist;
    }
};
