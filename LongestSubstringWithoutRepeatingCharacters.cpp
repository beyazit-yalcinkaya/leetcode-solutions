class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> sub_s;
        int n = s.size();
        int max = 0;
        map<char, bool> char_map;
        for (int i = 0; i < n; i++)
        {
            if (not char_map[s[i]])
            {
                sub_s.push(s[i]);
                char_map[s[i]] = true;
            }
            else
            {
                (max < sub_s.size()) ? (max = sub_s.size()) : (1);
                while (sub_s.front() != s[i])
                {
                    char_map[sub_s.front()] = false;
                    sub_s.pop();
                }
                if (sub_s.size() > 1)
                {
                    sub_s.pop();
                    sub_s.push(s[i]);
                }
                char_map[s[i]] = true;
            }
        }
        (max < sub_s.size()) ? (max = sub_s.size()) : (1);
        return max;        
    }
};