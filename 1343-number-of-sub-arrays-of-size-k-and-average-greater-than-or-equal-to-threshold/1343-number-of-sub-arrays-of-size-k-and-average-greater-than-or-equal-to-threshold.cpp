class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int left = 0, right = 0;
        int count = 0;
        int sum = 0;
        while (right < k) {

            sum += arr[right];
            right++;
        }
        if (sum >= threshold * k) {
            count++;
        }
        while (right < n) {
            sum -= arr[left];
            left++;

            sum += arr[right];
            right++;

            if (sum >= threshold * k) {
                count++;
            }
        }
        return count;
    }
};