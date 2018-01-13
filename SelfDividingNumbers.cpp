class Solution {
public:
    bool is_delf_dividing(int n) {
        int a = 0;
        int b = n;
        while (b != 0) {
            a = b % 10;
            b /= 10;
            if (a == 0 || n % a != 0)
                return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> out;
        for (int i = left; i <= right; i++)
            if (is_delf_dividing(i))
                out.push_back(i);
        return out;
    }
};
