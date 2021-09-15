class Solution{
  public:
    int MissingNumber(vector<int>& A, int n) {
        // Your code goes here
        int shudBe = 0, sum = 0;
        for(int i = 0; i<n-1;i++){
            sum += A[i];
        }
        shudBe = n*(n+1)/2;
        return shudBe - sum;
    }
};