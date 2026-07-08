#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        // Store only non-zero digits and their positions
        vector<int> digits;
        vector<int> pos;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        // prefix sum of digits
        vector<long long> prefixSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefixSum[i + 1] = prefixSum[i] + digits[i];
        }

        // powers of 10 modulo MOD
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // prefix numbers
        vector<long long> prefixNum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefixNum[i + 1] = (prefixNum[i] * 10 + digits[i]) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            // First non-zero digit >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // Last non-zero digit <= r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefixSum[R + 1] - prefixSum[L];

            long long num = (
                prefixNum[R + 1]
                - (prefixNum[L] * pow10[R - L + 1]) % MOD
                + MOD
            ) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};