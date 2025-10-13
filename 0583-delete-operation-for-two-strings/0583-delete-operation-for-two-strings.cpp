class Solution {
public:
vector<vector<int>>memo;
    int helper(string& word1, string& word2, int m, int n){
        if(m == 0 || n == 0) return 0;
        if(memo[m][n] != -1) return memo[m][n];
        
        if(word1[m-1]==word2[n-1]) return memo[m][n] = 1 + helper(word1, word2, m-1, n-1);
        else return memo[m][n] = max(helper(word1, word2, m-1, n),helper(word1, word2, m, n-1));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
       memo=vector<vector<int>>(m+1, vector<int>(n+1, -1));
        int CommonChar=helper(word1,word2,m,n);
        int steps=(m-CommonChar)+(n-CommonChar);
        return steps;

    }
};