class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int result=0;
        int number=0;
        int sign=1;
        for(auto i:s){
            if(isdigit(i)){
                number=number*10+(i-'0');
            }
            else if(i=='+'){
                result+=number*sign;
                number=0;
                sign=1;
            }
            else if(i=='-'){
                result+=number*sign;
                number=0;
                sign=-1;
            }
            else if(i=='('){
                st.push(result);
                st.push(sign);
                result=0;
                number=0;
                sign=1;
            }
            else if(i==')'){
                result+=number*sign;
                number=0;
                int stack_sign=st.top();
                st.pop();
                int stack_res=st.top();
                st.pop();
                result*=stack_sign;
                result+=stack_res;
            }
        }
        result+=number*sign;
        return result;
    }
};
