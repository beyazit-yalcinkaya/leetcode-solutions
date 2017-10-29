class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        int n = s.length();
        if (n % 2 == 1) return false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{') stck.push(s[i]);
            else
            {
                if (stck.empty()) return false;
                else if (s[i] == ')')
                {
                    if (stck.top() != '(') return false;
                    else stck.pop();
                }
                else if (s[i] == ']')
                {
                    if (stck.top() != '[') return false;
                    else stck.pop();
                }
                else if (s[i] == '}')
                {
                    if (stck.top() != '{') return false;
                    else stck.pop();
                }    
            }
        }
        if (stck.empty()) return true;
        else return false;
    }
};