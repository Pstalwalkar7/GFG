class Solution{
public:	
	
	int countTriplet(int A[], int n)
	{
	    sort(A, A+n);
	    int sum,l,r,cur;
	    int ans = 0;
	    for(int sumTo = n-1; sumTo>1;sumTo--){
	        sum = A[sumTo];
	        
	        l = 0;
	        r = sumTo-1;
	        
	        while(l<r){
	            cur = A[l] + A[r];
	           // cout<<sumTo<<" "<<l<<" "<<r<<"\n";
	            if (cur < sum){
	                l++;
	            }
	            else if(cur > sum){
	                r--;
	            }
	            else{
	                ans++;
	                l++;
	                r--;
	               // cout<<"RECOG:"<<sumTo<<" "<<l<<" "<<r<<"\n";
	            }
	        }
	    }
	    return ans;
	}
};