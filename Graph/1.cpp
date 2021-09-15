class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	void DFS(vector<int> adj[], vector<int> &vis, vector<int> &ret, int src){
	    
	    vis[src] = 1;
	    ret.push_back(src);
	    
	    for (auto i: adj[src]){
	        if (vis[i] == 0){
	            DFS(adj, vis, ret, i);
	        }
	    }  
	}
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<int> vis(V);
	    vector<int> ret;
	    DFS(adj, vis, ret, 0);
	    return ret;
	}
};