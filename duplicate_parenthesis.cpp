
#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str){
    stack<char>st;

    for(char ch:str)
    {

        if(ch==')')
        {  char top = st.top();
            st.pop();
            int elementsInside = 0;
            while (top != '(')
            {
                elementsInside++;
                top = st.top();
                st.pop();
            }
            if(elementsInside < 1) {
                return 1;
            }
        }
        else
            st.push(ch);
    }
    return false;


}

int main()
{

    string str = "((a+b)+(c+d))";

    if (duplicateParentheses(str))
        cout << "Duplicate Found ";
    else
        cout << "No Duplicates Found ";

    return 0;
}
