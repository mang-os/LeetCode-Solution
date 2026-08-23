class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        int left_sum = 0, right_sum = 0;
        int left_q = 0, right_q = 0;

        // Process left half
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') left_q++;
            else left_sum += num[i] - '0';
        }

        // Process right half
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') right_q++;
            else right_sum += num[i] - '0';
        }

        // Total question marks is odd -> Alice wins
        if ((left_q + right_q) % 2 != 0) {
            return true;
        }

        // Check if Bob can balance the sum difference using pairs of 9s
        return (left_sum - right_sum) * 2 != (right_q - left_q) * 9;
    }
};