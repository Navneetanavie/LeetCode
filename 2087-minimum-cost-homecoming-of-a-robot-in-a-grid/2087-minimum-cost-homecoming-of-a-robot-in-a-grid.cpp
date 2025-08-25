class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0;
        int r=startPos[0];
        int c=startPos[1];
        int dr=homePos[0];
        int dc=homePos[1];
        while(r<dr) ans+=rowCosts[++r];
        while(c<dc) ans+=colCosts[++c];
        while(r>dr) ans+=rowCosts[--r];
        while(c>dc) ans+=colCosts[--c];
         return ans;
    }
};