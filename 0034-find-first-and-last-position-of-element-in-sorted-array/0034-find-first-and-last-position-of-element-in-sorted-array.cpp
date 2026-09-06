class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();

        if(n < 1)
            return {-1, -1};

        int lower = -1;
        int upper = -1;

        // Find first occurrence
        int i = 0, j = n - 1;

        while(i <= j) {
            int m = i + (j - i) / 2;

            if(nums[m] >= t) {
                j = m - 1;
            }
            else {
                i = m + 1;
            }
        }

        if(i < n && nums[i] == t) {
            lower = i;
        }

        // Find last occurrence
        i = 0;
        j = n - 1;

        while(i <= j) {
            int m = i + (j - i) / 2;

            if(nums[m] <= t) {
                i = m + 1;
            }
            else {
                j = m - 1;
            }
        }

        if(j >= 0 && nums[j] == t) {
            upper = j;
        }

        return {lower, upper};
    }
};