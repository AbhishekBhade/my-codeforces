class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();

        if (n == 0)
            return -1;

        // Find index of minimum element
        int i = 0, j = n - 1;

        while (i < j) {
            int m = i + (j - i) / 2;

            if (nums[m] > nums[j]) {
                i = m + 1;
            }
            else {
                j = m;
            }
        }

        // i = index of minimum element
        int piv = i - 1;

        int p, q;

        // Array is not rotated
        if (piv == -1) {
            p = 0;
            q = n - 1;
        }
        // Target lies in left sorted part
        else if (t >= nums[0]) {
            p = 0;
            q = piv;
        }
        // Target lies in right sorted part
        else {
            p = piv + 1;
            q = n - 1;
        }

        // Normal binary search
        while (p <= q) {
            int m = p + (q - p) / 2;

            if (nums[m] == t) {
                return m;
            }
            else if (nums[m] > t) {
                q = m - 1;
            }
            else {
                p = m + 1;
            }
        }

        return -1;
    }
};