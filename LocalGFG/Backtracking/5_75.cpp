typedef vector<string> vs;
class Solution{
  public:
  
    bool valid_ip(string S){
        // complete this function later, with IP address validater program GFG
        return 1;
    }
    
    void generate_all(vs &ans, string &cur, int ind, string &s1, string &s2, int c1, int c2){
        if(c1 == s1.size() and c2 == s2.size()){
            if(valid_ip(cur)) ans.push_back(cur);
            return;
        }    
        if(c1 == s1.size()){  // no more numbers only dots.
            return;
        }
        
        cur[ind] = s1[c1];
        generate_all(ans, cur, ind + 1, s1, s2, c1 + 1, c2);
        
        if(c2 != s2.size()){
            if(ind and cur[ind-1] != '.'){
                cur[ind] = s2[c2];
                generate_all(ans, cur, ind + 1, s1, s2, c1, c2 + 1);
            }
        } 
    }
    
    vector<string> genIp(string &s) {
        // Your code here
        string t = "...";
        string cur = "";
        for(int i = 0; i<s.size() + t.size();i++) cur += "-";
        // cout<<cur<<"\n";
        
        int c1, c2;
        c1 = 1;
        c2 = 0;
        
        vs ans;
        cur[0] = s[0];
        int ind = 1;
        generate_all(ans, cur, ind, s, t, c1, c2);
        
        return ans;
    }

};