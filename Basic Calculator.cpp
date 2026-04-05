class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        long long number = 0;
        long long result = 0;
        long long sign = 1;

        for (auto i : s) {
            if (isdigit(i)) {
                number = number * 10 + (i - '0');
            }
            else if (i == '+') {
                result += number * sign;
                number = 0;
                sign = 1;
            }
            else if (i == '-') {
                result += number * sign;
                number = 0;
                sign = -1;
            }
            else if (i == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            }
            else if (i == ')') {
                result += number * sign;
                number = 0;

                long long stack_sign = st.top(); st.pop();
                long long stack_res = st.top(); st.pop();

                result *= stack_sign;
                result += stack_res;
            }
        }

        result += number * sign;
        return (int)result;  // cast back if required
    }
};
