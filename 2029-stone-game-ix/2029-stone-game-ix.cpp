class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Array to store the frequency of stones with mod 0, 1, and 2
        int counts[3] = {0, 0, 0};
        
        for (int stone : stones) {
            counts[stone % 3]++;
        }
        
        // If the number of stones divisible by 3 is even
        if (counts[0] % 2 == 0) {
            // Alice wins if there is at least one 1 and at least one 2
            return counts[1] > 0 && counts[2] > 0;
        } else {
            // If the number of stones divisible by 3 is odd
            // Alice wins only if the difference between 1s and 2s is greater than 2
            return abs(counts[1] - counts[2]) > 2;
        }
    }
};