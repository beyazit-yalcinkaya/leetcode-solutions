class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int output = 0;
        for (int i = 0; i < n; i++)
        {
            switch (s[i])
            {
                case 'I':
                    {
                        if (i < n - 1)
                        {
                            if (s[i + 1] == 'V' or s[i + 1] == 'X')
                            {
                                output -= 1;
                                break;
                            }
                        }
                        output += 1;
                        break;
                    }
                case 'V':
                    {
                        output += 5;
                        break;
                    }
                case 'X':
                    {
                        if (i < n - 1)
                        {
                            if (s[i + 1] == 'L' or s[i + 1] == 'C')
                            {
                                output -= 10;
                                break;
                            }
                        }
                        output += 10;
                        break;
                    }
                case 'L':
                    {
                        output += 50;
                        break;
                    }
                case 'C':
                    {
                        if (i < n - 1)
                        {
                            if (s[i + 1] == 'D' or s[i + 1] == 'M')
                            {
                                output -= 100;
                                break;
                            }
                        }
                        output += 100;
                        break;
                    }
                case 'D':
                    {
                        output += 500;
                        break;
                    }
                case 'M':
                    {
                        output += 1000;
                        break;                    }
            }
        }
        return output;        
    }
};