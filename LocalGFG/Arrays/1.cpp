#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int A[], int n, int s)
    {
        // Your code here
        int store = 0;
        int l = 0, r= 0;
        
        for (;r<n;){
            while(store < s){
                store += A[r++];
            }
            while(store > s){
                store -= A[l++];
            }
            if(store == s){
                return {l+1,r};
            }
        }
        return {-1};
    }
};