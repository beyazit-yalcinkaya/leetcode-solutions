class Solution {
public:
    int help(int num, int rnum)
    {
        if (num == 0) return rnum;
        else
        {
            return help(num / 10, rnum * 10 + num % 10);
        }
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        else if (x < 10) return true;
        return x == help(x / 10, x % 10);        
    }
};