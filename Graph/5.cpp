class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> G[]) 
	{
	    vector<int> I(V);
	    vector<int> ret;
	    
	    queue<int> Q;
	    
	    for(int i = 0; i<V;i++){
	        for(auto x : G[i]){
	            I[x]++;
	        }
	    }
	    
	    for(int i = 0; i<V;i++){
	        if(I[i] == 0) Q.push(i);
	    }
	    
	    int cur;
	    while(!Q.empty()){
	        cur = Q.front();
	        for(auto x: G[cur]){
	            I[x]--;
	            if(I[x] == 0) Q.push(x);
	        }
	        ret.push_back(cur);
	        Q.pop();
	    }
	    return ret;
	}
};