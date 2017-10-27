class Solution {
public:
    int reverse(int x) {
        bool isnegative;
        if (x < 0)
        {
            isnegative = true;
            x *= (-1);
        }
        else
        {
            isnegative = false;
        }
        char a;
        string temp = to_string(x);
        string maxpos = "2147483647";
        string maxneg = "2147483648";
        for (int i = 0, j = temp.size() - 1; i < j; i++, j--)
        {
            a = temp[i];
            temp[i] = temp[j];
            temp[j] = a;            
        }
        if (temp.size() == 10)
        {
            if (temp[0] >'2') return 0;
            else if (temp[0] ='2')
            {
                if (isnegative)
                {
                    for (int i = 1; i < 10; i++)
                    {
                        if (temp[i] > maxneg[i]) return 0;
                        else if (temp[i] == maxneg[i]) continue;
                        else break;
                    }
                    return stoi(temp, nullptr) * (-1);
                }
                else
                {
                    for (int i = 1; i < 10; i++)
                    {
                        if (temp[i] > maxpos[i]) return 0;
                        else if (temp[i] == maxpos[i]) continue;
                        else break;
                    }
                    return stoi(temp, nullptr);
                }
            }
            else
            {
                if (isnegative)
                {
                    return stoi(temp, nullptr) * (-1);
                }
                else
                {
                    return stoi(temp, nullptr);
                }                
            }
        }
        else if (temp.size() >= 10) return 0;
        else
        {
            if (isnegative)
            {
                return stoi(temp, nullptr) * (-1);
            }
            else                {
                return stoi(temp, nullptr);
            }            
        }
    }
};