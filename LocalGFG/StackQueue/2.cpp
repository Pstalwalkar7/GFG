class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> A, int n){
        // Your code here
        stack<long long> S;
        vector<long long> V(n,-1);
        for(int i = 0; i<n;i++){
            while(!S.empty() and A[i] > A[S.top()]){
                V[S.top()] = A[i]; 
                S.pop();
            }
            S.push(i);
        }
        return V;
    }
};