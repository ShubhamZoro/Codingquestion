// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]
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
