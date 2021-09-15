class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	
	bool DFS(vector<int> G[], vector<int> vis, int src, int parent){
	    vis[src] = 1;
	    bool flag = 0;
	    for(auto x: G[src]){
	        if(vis[x] == 0){
	            flag = DFS(G, vis, x, src);
	        }
	        else if(x != parent){
	            return 1;
	        }
	        if(flag == 1) break;
	    }
	    return flag;
	}
	
	bool isCycle(int V, vector<int>adj[])
	{
	    bool flag = 0;
	    vector<int> vis(V+1);
	    for(int i = 0; !flag and i<V;i++){
	        flag = DFS(adj, vis, i, -1);
	    }
	    
	    return flag;
	}
};