class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        
        // 1. Create a sorted copy of unique elements
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        // Remove duplicates to get unique elements only
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());
        
        // 2. Map each element to its rank (index + 1)
        unordered_map<int, int> rankMap;
        for (int i = 0; i < sortedArr.size(); ++i) {
            rankMap[sortedArr[i]] = i + 1;
        }
        
        // 3. Transform the original array
        vector<int> result;
        result.reserve(arr.size());
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        
        return result;
    }
};