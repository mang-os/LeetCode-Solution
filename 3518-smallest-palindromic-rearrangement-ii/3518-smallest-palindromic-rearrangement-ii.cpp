#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Computes C(n, r) with a cap to prevent overflow
    long long nCr(int n, int r, long long cap) {
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * n / i;
            n--;
            if (res > cap) return cap + 1;
        }
        return res;
    }

    // Calculates the total unique permutations for the given character counts
    long long calc(const vector<int>& counts, int len, long long cap) {
        long long ways = 1;
        int remain = len;
        for (int c : counts) {
            if (c == 0) continue;
            ways *= nCr(remain, c, cap);
            if (ways > cap) return cap + 1;
            remain -= c;
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> counts(26, 0);
        char mid_char = 0;
        int m = s.length() / 2;

        // Halve the frequencies for the left side of the palindrome
        for (int i = 0; i < 26; ++i) {
            counts[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) {
                mid_char = i + 'a';
            }
        }

        // If total palindromic permutations are less than k, return ""
        long long total_perms = calc(counts, m, k);
        if (total_perms < k) {
            return "";
        }

        string left_half = "";
        
        // Build the left half character by character
        for (int i = 0; i < m; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (counts[c] > 0) {
                    counts[c]--; // Temporarily pick this character
                    
                    // Calculate permutations for the remaining characters
                    long long perms = calc(counts, m - 1 - i, k);
                    
                    if (perms >= k) {
                        left_half += (char)(c + 'a');
                        break; // Move to the next position in left_half
                    } else {
                        k -= perms;
                        counts[c]++; // Revert and try the next character
                    }
                }
            }
        }

        // Generate the right half by mirroring the left
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());

        // Assemble the final palindrome
        if (s.length() % 2 != 0) {
            return left_half + mid_char + right_half;
        } else {
            return left_half + right_half;
        }
    }
};