class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        for(int i=0;i<s.size();i++){
             res+=count_palindrome(s,i,i);
             res+=count_palindrome(s,i,i+1);
        }
        return res;
    }
    int count_palindrome(string s, int left, int right){
        int cnt=0;
        while(left>=0&&right<s.length()&&s[left]==s[right]){
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
};