class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;
        for(char c: s){
            if(c =='(' || c == '*'){
                balance++;
            }
            else{
                balance--;
            }
            if(balance<0){
                return false;
            }
        }
        balance = 0;
        for(int i=s.size()-1; i>=0; i--){
            char c = s[i];
            if(c ==')' || c == '*'){
                balance++;
            }
            else{
                balance--;
            }
            if(balance<0){
                return false;
            }
        }
        return true;
    }
};
