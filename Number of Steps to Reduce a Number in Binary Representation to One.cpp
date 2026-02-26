class Solution {
public:
    int numSteps(string s) {
         int steps = 0;
        int carry = 0;

        // Traverse from right to left (except first bit)
        for (int i = s.size() - 1; i > 0; i--) {
            if ((s[i] - '0' + carry) == 1) {
                // odd case → +1 then /2
                steps += 2;
                carry = 1;
            } else {
                // even case → just /2
                steps += 1;
            }
        }

        return steps + carry;
    }
};
