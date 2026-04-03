class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto i:tokens){
            if(i=="+"){
                int p=s.top();
                s.pop();
                int k=s.top();
                s.pop();
                s.push(p+k);
            }
            else if(i=="-"){
                int p=s.top();
                s.pop();
                int k=s.top();
                s.pop();
                s.push(k-p);
            }
            else if(i=="*"){
                int p=s.top();
                s.pop();
                int k=s.top();
                s.pop();
                s.push(p*k);
            }
            else if(i=="/"){
                int p=s.top();
                s.pop();
                int k=s.top();
                s.pop();
                s.push(k/p);
            }
            else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};
