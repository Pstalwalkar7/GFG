class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    
    void BFS(vector<int> adj[], vector<int> &vis, vector<int> &ret, int src){
        
        queue<int> Q;
        Q.push(src);
        int cur;
        vis[src] = 1;
        
        while(!Q.empty()){
            
            cur = Q.front();
            ret.push_back(cur);
            
            for (auto i: adj[cur]){
                
                if(vis[i] == 0){
                    Q.push(i);
                    vis[i] = 1;
                }
                
            }
            Q.pop();
        }
        
    }
    
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> ret;
	    vector<int> vis(V);
	    
	    BFS(adj, vis, ret, 0);
	    
	    return ret;
	}
};