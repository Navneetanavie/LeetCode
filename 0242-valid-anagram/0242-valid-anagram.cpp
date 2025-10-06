class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash_S[26]={0};
        int hash_T[26]={0};
        for(auto it:s){
            hash_S[it-'a']++;
        }
        for(auto it:t){
            hash_T[it-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash_S[i]!=hash_T[i])
            return false;
        }
        return true;

    }
};