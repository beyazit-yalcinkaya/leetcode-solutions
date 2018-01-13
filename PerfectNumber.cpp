class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
            return false;
        int a = 1;
        int temp = sqrt(num);
        for (int i = 2; i <= temp; i++)
            if (num % i == 0)
                a += i + num / i;
        return (a == num) ? (true) : (false);
    }
};
