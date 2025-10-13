class Solution {
public:

    int helper(string& word1, string& word2, int m, int n, vector<vector<int>>& memo){
        if(m == 0 || n == 0) return 0;
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if(word1[m-1] == word2[n-1])
            return memo[m][n] = 1 + helper(word1, word2, m-1, n-1, memo);
        else
            return memo[m][n] = max(
                                    helper(word1, word2, m-1, n, memo), 
                                    helper(word1, word2, m, n-1, memo)
                                );
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
       vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        int CommonChar=helper(word1,word2,m,n,memo);
        int steps=(m-CommonChar)+(n-CommonChar);
        return steps;

    }
};