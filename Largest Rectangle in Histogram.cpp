class Solution {
public:
    vector<int>getNSE(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        vector<int>NSE(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                NSE[i]=n;
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSE[i]=n;
                }
                else{
                    NSE[i]=st.top();
                }
                
            }
            st.push(i);
        }
        return NSE;
    }

    vector<int>getPSE(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        vector<int>PSE(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                PSE[i]=-1;
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    PSE[i]=-1;
                }
                else{
                    PSE[i]=st.top();
                }
                
            }
            st.push(i);
        }
        return PSE;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int>NSE=getNSE(heights);
        vector<int>PSE=getPSE(heights);
    int n=heights.size();
    int maxarea=0;
        for(int i=0;i<n;i++){
            int width=NSE[i]-PSE[i]-1;
            int area=heights[i]*width;
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};
