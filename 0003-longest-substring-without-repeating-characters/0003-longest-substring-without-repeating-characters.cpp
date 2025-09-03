class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxLen=0;
       int left=0;
       unordered_set<char>nonRepeating;
       for(int right=0;right<s.size();right++){
           if(nonRepeating.count(s[right])==0){
                nonRepeating.insert(s[right]);
           }
           else{
            while(nonRepeating.count(s[right])!=0){
                nonRepeating.erase(s[left]);
                left++;
            }
            nonRepeating.insert(s[right]);
           }
           maxLen=max(maxLen,right-left+1);
       }
      return maxLen;
    }
};