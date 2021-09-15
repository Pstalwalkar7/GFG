int maxChainLen(struct val p[],int n)
{
    vector<pair<int, int>> P(n);
    for(int i = 0; i<n;i++){
        P[i].first = p[i].first;
        P[i].second = p[i].second;
    }
    
    sort(P.begin(), P.end());
    
    vector<int> chain(n, 1);
    for(int i = 1; i<n;i++){
        for(int j = 0; j<i; j++){
            if (P[j].second < P[i].first){
                chain[i] = max(chain[i], chain[j] + 1);
            }
        }
    }
    int mx = 0;
    for(int i=0;i<n;i++){
        mx = max(chain[i], mx);
    }
    return mx;
}