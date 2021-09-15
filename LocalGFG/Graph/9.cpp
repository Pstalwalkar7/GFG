class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void DFS(vector<int> G[], vector<int> &vis, int src, stack<int> &S){
	    vis[src] = 1;
	   // cout<<src<<" ";
	    for(auto x: G[src]){
	        if(vis[x] == 0){
	            DFS(G, vis, x, S);
	        }
	    }
	    S.push(src);
	}
	
    int kosaraju(int V, vector<int> G[]){
        // IF we just needed #SCC, formula = max(#islands in G, #islands in GT) shud also work, but this is kosaraju
        
        // ALGO: Do DFS, but keep a stack and push at end of recursive call/ keep a queue and push at start of recursive call.
        vector<int> GT[V];
        for(int i = 0; i<V;i++){
            for(auto x: G[i]){
                GT[x].push_back(i);
            }
        }
        stack<int> S;
        stack<int> X; // completely useless, just contains the traversal, but kept for f() call sake
        vector<int> vis(V);
        for(int i = 0; i<V;i++){
            if(vis[i] == 0) DFS(G, vis, i, S);
        }
        // cout<<"\n";
        int x;
        int cnt = 0;
        fill(vis.begin(), vis.end(), 0);
        while(!S.empty()){
            x = S.top();
            // cout<<x<<" ";
            S.pop();
            if(vis[x] == 0){
                cnt++;
                DFS(GT, vis, x, X);
                // cout<<"\n";
            }
        }
        return cnt;
    }
};