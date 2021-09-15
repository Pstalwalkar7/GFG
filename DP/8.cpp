class Solution{
		

	public:
	int maxSumIS(int A[], int n)  
	{  
	    vector<int> dp(n);
	   // dp[0] = A[0];
	    for(int i = 0; i<n;i++){
	        dp[i] = A[i];
	    }
	    
	    for(int i = 1; i<n;i++){
	        for(int j = 0; j<i; j++){
	            if(A[j] < A[i]){
	                dp[i] = max(dp[i], dp[j] + A[i]);
	            }
	        }
	    }
	    
	    int mx = 0;
	    for(int i = 0; i<n;i++){
	       // cout<<dp[i]<<" ";
	        mx = max(mx, dp[i]);
	    }
	   // cout<<"\n";
	    return mx;
	}  
};