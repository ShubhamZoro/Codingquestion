#include<iostream>
using namespace std;
class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {

    }

    int next(int price) {
        int s=1;
        while(!st.empty() && st.top().second <= price){
            s += st.top().first;
            st.pop();
        }
        st.push({s, price});

        return s;
    }

};
