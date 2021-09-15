class Solution:
    
    #Function to reverse words in a given string.
    def reverseWords(self,S):
        # code here 
        
        L = S.split('.')
        X = [L[i] for i in range(len(L) - 1, -1,-1)]
        sep = '.'
        Y = sep.join(X)
        return Y
