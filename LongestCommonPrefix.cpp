class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        for (auto i = 0; i < strs[0].size(); i++)
            for (auto j = 1; j < strs.size(); j++)
                if (strs[0][i] != strs[j][i]) return strs[0].substr(0, i);        
        return strs[0];     
    }
};