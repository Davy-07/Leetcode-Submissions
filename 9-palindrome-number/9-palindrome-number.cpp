class Solution {
public:
    bool isPalindrome(int x) {
        
        long int reverse = 0;
        long int current = x;
        while(current>0)
        {
            reverse= reverse*10 + current%10;
            current/=10;
        }
        return (reverse==x);
        
    }
};