class Solution {
public:
    bool checkPerfectNumber(int num) {
        int a = 1;
        if (num == 1)
            return false;
        for (int i = 2; i <= sqrt(num); i++)
            if (num % i == 0)
                a += i + num / i;
        return (a == num) ? (true) : (false);
    }
};
