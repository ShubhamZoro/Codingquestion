class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long marea=0;
            vector<vector<int>>intersectbot;
            vector<vector<int>>intersecttop;
            for(int i=0;i<bottomLeft.size();i++){
                for(int j=i+1;j<bottomLeft.size();j++){
                   
                    int bx=max(bottomLeft[i][0],bottomLeft[j][0]);
                    int by=max(bottomLeft[i][1],bottomLeft[j][1]);
                    int tx=min(topRight[i][0],topRight[j][0]);
                    int ty=min(topRight[i][1],topRight[j][1]);
                    if (tx > bx && ty > by) {   
                    long long side = min(tx - bx, ty - by);
                    marea = max(marea, side * side);
                }
                }
            }
            return marea;
    }
};
