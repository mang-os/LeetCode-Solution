class Solution {
private:
    string freeSlotsFiller(long long required, int length) {
        string str = "";
        
        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                str.push_back(digit + '0');
                required /= digit;
            }
        }
        
        while ((int)str.length() < length) {
            str.push_back('1');
        }
        
        reverse(str.begin(), str.end());
        return str;
    }

public:
    string smallestNumber(string num, long long t) {
        int n = num.length();

        long long temp = t;
        int primeFactors[] = {2, 3, 5, 7};
        for (int pf : primeFactors) {
            while (temp % pf == 0) {
                temp /= pf;
            }
        }
        if (temp != 1) return "-1"; 

        vector<long long> remainingFactor(n + 1, t);
        for (int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            remainingFactor[i + 1] = remainingFactor[i] / std::gcd(remainingFactor[i], (long long)digit);
        }

        if (remainingFactor[n] == 1 && num.find('0') == string::npos) {
            return num;
        }

        size_t zeroPos = num.find('0');
        int zeroIndex = (zeroPos == string::npos) ? n - 1 : (int)zeroPos;

        for (int i = zeroIndex; i >= 0; i--) {
            long long required = remainingFactor[i];
            int freeSlots = n - 1 - i;
            int currentDigit = num[i] - '0';

            for (int d = currentDigit + 1; d <= 9; d++) {
                long long furtherRequired = required / std::gcd(required, (long long)d);
                string reqNum = freeSlotsFiller(furtherRequired, freeSlots);

                if ((int)reqNum.length() == freeSlots) {
                    return num.substr(0, i) + to_string(d) + reqNum;
                }
            }
        }

        return freeSlotsFiller(t, n + 1);
    }
};