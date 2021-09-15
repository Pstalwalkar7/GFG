typedef long long ll;
class Solution{
    public:
        //Function to merge the arrays.
        void swap(ll A[], ll B[], int i, int j){
            ll t = A[i];
            A[i] = B[j];
            B[j] = t;
        }
        void merge(ll A[], ll B[], int n, int m) 
        { 
            ll l = 0;
            ll r = 0;
            ll k = n-1;
            
            while(l<n and r<m){
                if(A[l] <= B[r]){
                    l++;
                }
                else{
                    swap(A, B, k, r);
                    r++;
                    k--;
                    // r++; 
                }
            }
            sort(A, A + n);
            sort(B, B + m);
        } 
};