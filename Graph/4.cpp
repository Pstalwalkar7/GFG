class Solution
{
    public:
    
    bool DFS(vector<int> G[], vector<int> &vis, int src){
        vis[src] = 1;
        bool flag =0;
        for(auto x: G[src]){
            if(vis[x] == 1){
                vis[x] = 0;
                return 1;
            }
            if(vis[x] == 0){
                flag = DFS(G, vis, x);
            }
            if(flag) break;
        }
        vis[src] = 2;
        return flag;
    }
    
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V);
	    bool flag = 0;
	   	for(int i = 0 ;!flag and i< V; i++){
	   	    if(vis[i] == 0){
	   	        flag = DFS(adj, vis, i);
	   	    }
	   	}
	   	return flag;
	}
};