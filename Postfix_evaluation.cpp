#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int postfix_evaluation(string s)
{
    stack<int>st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else{
            int k=st.top();
            st.pop();
            int j=st.top();
            st.pop();
            switch(s[i])
            {
            case '+':
                st.push(j=k);
                break;
            case '-':
                st.push(j-k);
                break;
            case '*':
                st.push(j*k);
                break;
            case '/':
                st.push(j/k);
                break;
            case '^':
                st.push(pow(j,k));
                break;
            default:
                break;
            }
        }
    }
     return st.top();
}
int main()
{
   int k=postfix_evaluation("563/-");
    cout<<k;
}

