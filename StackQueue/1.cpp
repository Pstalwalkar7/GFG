class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> S;
        map<char, char> adj = {};
        adj['}'] = '{';
        adj[']'] = '[';
        adj[')'] = '(';
        
        for(int i = 0; i<x.size(); i++){
            if(x[i] == '{' or x[i] == '(' or x[i] == '['){
                S.push(x[i]);
            }
            else{
                if(S.empty() or S.top() != adj[x[i]] ){
                    return false;
                }
                else{
                    S.pop();
                }
            }
        }
        if(S.empty()) return true;
        else return false;
    }

};