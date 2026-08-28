class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        char center = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                if (center != 0) return ""; // More than one odd frequency
                center = 'a' + i;
                freq[i]--;
            }
        }
        
        int n = s.length();
        int half = n / 2;
        
        // Helper to check if we have enough characters
        auto check = [](const vector<int>& f) {
            for (int x : f) if (x < 0) return false;
            return true;
        };
        
        // Scenario 1: Try an exact match of target's first half
        vector<int> tempFreq = freq;
        for (int i = 0; i < half; i++) {
            tempFreq[target[i] - 'a'] -= 2;
        }
        
        if (check(tempFreq)) {
            string head = target.substr(0, half);
            string rev = head;
            reverse(rev.begin(), rev.end());
            
            string tail = "";
            if (center != 0) tail += center;
            tail += rev;
            
            // If copying the first half makes the whole string strictly greater, we're done
            if (tail > target.substr(half)) {
                return head + tail;
            }
        }
        
        // Scenario 2: We need to increase a character in the first half to make it > target
        // We traverse right-to-left to find the rightmost character we can increase
        for (int i = half - 1; i >= 0; i--) {
            char w = target[i];
            tempFreq[w - 'a'] += 2; // Restore the character to our available pool
            
            if (!check(tempFreq)) continue; // Skip if we don't even have enough chars for the prefix
            
            // Try the next available character strictly greater than target[i]
            for (int j = (w - 'a') + 1; j < 26; j++) {
                if (tempFreq[j] == 0) continue;
                tempFreq[j] -= 2;
                
                string result = target.substr(0, i);
                result += ('a' + j);
                
                // Fill the remaining spots with the smallest available characters
                for (int k = 0; k < 26; k++) {
                    int cnt = tempFreq[k] / 2;
                    if (cnt > 0) {
                        result.append(cnt, 'a' + k);
                    }
                }
                
                // Mirror the first half to complete the palindrome
                string part = result;
                reverse(part.begin(), part.end());
                
                if (center != 0) result.push_back(center);
                result += part;
                
                return result;
            }
        }
        
        return "";
    }
};