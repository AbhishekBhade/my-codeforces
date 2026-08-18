class Solution {
public:
    int largestInteger(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        
        // Count frequencies
        for (int x : arr) freq[x]++;
        
        // Case 1: k == n
        // All elements appear in exactly one subarray (the whole array).
        // Return the largest element.
        if (k == n) {
            int maxVal = INT_MIN;
            for (int x : arr) {
                if (x > maxVal) maxVal = x;
            }
            return maxVal;
        }
        
        // Case 2: k == 1
        // Return the largest element that appears exactly once.
        if (k == 1) {
            int ans = INT_MIN;
            for (auto& [val, count] : freq) {
                if (count == 1) {
                    if (val > ans) ans = val;
                }
            }
            return (ans == INT_MIN) ? -1 : ans;
        }
        
        // Case 3: 1 < k < n
        // Only elements at the boundaries (index 0 and index n-1) can appear exactly once.
        // Elements in the middle always appear in at least 2 subarrays.
        int first = arr[0];
        int last = arr[n - 1];
        
        bool firstUnique = (freq[first] == 1);
        bool lastUnique = (freq[last] == 1);
        
        if (firstUnique && lastUnique) {
            return max(first, last);
        }
        if (firstUnique) {
            return first;
        }
        if (lastUnique) {
            return last;
        }
        
        return -1;
    }
};