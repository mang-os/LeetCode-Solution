class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        string s = "123456789";
        
        // 1. Loop through all possible lengths (from 2 up to 9)
        for (int len = 2; len <= 9; ++len) {
            // 2. Slide the window of size 'len' across the string
            for (int i = 0; i <= 9 - len; ++i) {
                // 3. Extract the substring and convert to integer
                string sub = s.substr(i, len);
                int num = stoi(sub);
                
                // 4. Check if it's in the valid range
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        
        return result;
    }
};