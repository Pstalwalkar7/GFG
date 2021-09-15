class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>> A(n);
	    vector<int> vis(n);
	    
	    for(int i = 0; i<n;i++){
	        A[i].first = nums[i];
	        A[i].second = i;
	    }
	    
	    sort(A.begin(), A.end());
	    int cycle_size;
	    
	    int ans = 0;
	    
	    for(int i = 0; i<n;i++){
	        
	        if(vis[i] or A[i].second == i){
	            continue;
	        }
	        
	        cycle_size = 0;
	        
	        while(!vis[i]){
	            vis[i] = 1;
	            cycle_size++;
	            i = A[i].second;
	        }
	        
	        ans += cycle_size - 1;
	        
	    }
	    
	    return ans;
	}
};