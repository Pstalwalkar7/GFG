class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> curr = {2000, 500, 200, 100, 50, 20, 10,5, 2, 1};
        vector<int> X;
        while(N){
            
            for(int i = 0; i<10; i++){
                if(curr[i] <= N){
                    X.push_back(curr[i]);
                    N -= curr[i];
                    break;
                }
            }
        }
        return X;
    }
};