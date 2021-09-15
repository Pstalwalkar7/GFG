class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int ans = 1;
        while(n){
            if(n%2) return ans;
            n/=2;
            ans++;
        }
        return 0;
    }
};