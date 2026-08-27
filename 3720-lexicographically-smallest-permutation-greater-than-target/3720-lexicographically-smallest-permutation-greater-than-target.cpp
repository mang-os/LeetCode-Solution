class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp = count;
            bool possible = true;
            
            for (int j = 0; j < i; j++) {
                if (--temp[target[j] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) continue;
            
            for (int j = target[i] - 'a' + 1; j < 26; j++) {
                if (temp[j] > 0) {
                    temp[j]--;
                    string res = target.substr(0, i) + (char)('a' + j);
                    
                    for (int k = 0; k < 26; k++) {
                        res += string(temp[k], 'a' + k);
                    }
                    
                    return res;
                }
            }
        }
        
        return "";
    }
};