class Solution {
public:
    bool isPalindrome(int x) {
        
        string num = to_string(x);
        reverse(num.begin(),num.end());
        if(num == to_string(x))
        {
            return true;
        }
        else{
            return false;
        }
        
    }
};