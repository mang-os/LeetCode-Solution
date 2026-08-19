class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, int> rowMasks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Only seats 2 to 9 matter for 4-person allocations
            if (col >= 2 && col <= 9) {
                rowMasks[row] |= (1 << (col - 2));
            }
        }
        
        // Rows with no reserved seats can accommodate 2 families each
        int maxFamilies = (n - rowMasks.size()) * 2;
        
        for (const auto& [row, mask] : rowMasks) {
            bool left = (mask & 0b00001111) == 0;   // Seats 2, 3, 4, 5 free
            bool right = (mask & 0b11110000) == 0;  // Seats 6, 7, 8, 9 free
            bool middle = (mask & 0b00111100) == 0; // Seats 4, 5, 6, 7 free
            
            if (left && right) {
                maxFamilies += 2;
            } else if (left || right || middle) {
                maxFamilies += 1;
            }
        }
        
        return maxFamilies;
    }
};