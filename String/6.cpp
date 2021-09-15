int romanToDecimal(string &S) {
    map<char, int> M = {};
    M.insert({'I', 1});
    M.insert({'V', 5});
    M.insert({'X', 10});
    M.insert({'L', 50});
    M.insert({'C', 100});
    M.insert({'D', 500});
    M.insert({'M', 1000});
    
    int ans = 0;
    int n = S.size();
    
    for(int i = 0; i<n;i++){
        if(i!=n-1 and M[S[i+1]] > M[S[i]]){
            ans -= M[S[i]];
        }
        else{
            ans += M[S[i]];
        }
    }
    
    return ans;
}