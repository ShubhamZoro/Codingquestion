#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int prefix_evaluation(string s)
{
    stack<int>st;
    for(int i=s.length()-1;i>=0;i--)
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
                st.push(k+j);
                break;
            case '-':
                st.push(k-j);
                break;
            case '*':
                st.push(k*j);
                break;
            case '/':
                st.push(k/j);
                break;
            case '^':
                st.push(pow(k,j));
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
   int k=prefix_evaluation("-+7*45+20");
    cout<<k;
}
