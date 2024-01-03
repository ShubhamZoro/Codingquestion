class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, temp = 0;
        for (int i = 0; i < bank.size(); i++) {
            int n=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    n++;
                }
            }
            if (n == 0) continue;
            ans += temp * n;;
            temp = n;
        }
        return ans;
    }
};
