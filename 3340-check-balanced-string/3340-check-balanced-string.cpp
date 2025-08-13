class Solution {
public:
    bool isBalanced(string num) {
        int sumE=0;
        int sumO=0;
        for(int i=0;i<num.size();i+=2){
            sumE+=num[i]-'0';
        }
        for(int i=1;i<num.size();i+=2){
            sumO+=num[i]-'0';
        }
        return sumE==sumO;
    }
};