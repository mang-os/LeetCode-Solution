class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> counts(26, 0);
        
        // Count the frequency of each character
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        string first_half = "";
        string middle = "";
        
        // Build the first half and find the middle character
        for (int i = 0; i < 26; i++) {
            if (counts[i] % 2 != 0) {
                middle = (char)('a' + i);
            }
            // Append half of the characters to the first half
            first_half.append(counts[i] / 2, (char)('a' + i));
        }
        
        // The second half is just the reverse of the first half
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());
        
        // Combine all parts
        return first_half + middle + second_half;
    }
};