class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string S1, string S2)
    {
        vector<vector<int>> dp(x, vector<int> (y));
        bool fill = 0; 
        for(int i = 0; i<x;i++){
            if(S1[i] == S2[0]){
                fill = 1;
            }
            dp[i][0] = fill;
        }
        fill = 0; 
        for(int i = 0; i<y; i++){
            if(S1[0] == S2[i]){
                fill = 1;
            }
            dp[0][i] = fill;
        }
        
        for(int i = 1; i<x;i++){
            for(int j = 1; j<y;j++){
                if(S1[i] == S2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        int mx = 0;
        for(int i= 0; i<x;i++){
            for(int j = 0; j<y;j++){
                mx = max(mx, dp[i][j]);
            }
        }
        
        return mx;
    }
};