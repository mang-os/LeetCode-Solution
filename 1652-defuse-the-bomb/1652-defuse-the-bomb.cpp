class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;

        vector<int> arr(2 * n);

        for (int i = 0; i < 2 * n; i++)
            arr[i] = code[i % n];

        int start, end;

        if (k > 0) {
            start = 1;
            end = k;
        } else {
            k = -k;
            start = n - k;
            end = n - 1;
        }

        int windowSum = 0;

        for (int i = start; i <= end; i++)
            windowSum += arr[i];

        for (int i = 0; i < n; i++) {

            ans[i] = windowSum;

            windowSum -= arr[start];
            start++;

            end++;
            windowSum += arr[end];
        }

        return ans;
    }
};