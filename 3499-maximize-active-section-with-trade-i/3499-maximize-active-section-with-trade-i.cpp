class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";

        int active = 0;
        int leftZeros = 0, rightZeros = 0;
        bool seenZero = false, seenOne = false, collectingRight = false;
        int bestGain = INT_MIN;

        for (char ch : s) {
            if (ch == '0') {
                if (seenZero && seenOne) {
                    collectingRight = true;
                    rightZeros++;
                } else if (!seenOne) {
                    seenZero = true;
                    leftZeros++;
                }
            } else {
                if (seenZero)
                    seenOne = true;

                if (seenZero && seenOne && collectingRight) {
                    bestGain = max(bestGain, leftZeros + rightZeros);
                    leftZeros = rightZeros;
                    rightZeros = 0;
                    collectingRight = false;
                }

                active++;
            }
        }

        if (seenZero && seenOne && collectingRight)
            bestGain = max(bestGain, leftZeros + rightZeros);

        active -= 2;

        return bestGain == INT_MIN ? active : active + bestGain;
    }
};