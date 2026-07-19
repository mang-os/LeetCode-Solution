class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        vector<bool> seen(26, false);
        string result = "";
        
        // Step 1: Record the last occurrence index of each character
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        // Step 2: Build the result using a monotonic stack approach
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If the character is already in our result string, skip it
            if (seen[c - 'a']) continue;
            
            // Pop characters from the end of result if they are lexicographically 
            // greater than the current character AND they appear again later in the string
            while (!result.empty() && result.back() > c && lastIndex[result.back() - 'a'] > i) {
                seen[result.back() - 'a'] = false; // Mark as unseen since we removed it
                result.pop_back();
            }
            
            // Add the current character and mark as seen
            result.push_back(c);
            seen[c - 'a'] = true;
        }
        
        return result;
    }
};