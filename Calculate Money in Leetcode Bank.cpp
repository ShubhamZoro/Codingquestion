class Solution {
public:
    int totalMoney(int n) {
        // int sum=0;
        // vector<int>money(7);
        // for(int i=0;i<7;i++){
        //     money[i]=i+1;
        // }
        // for(int i=0;i<n;i++){
        //     sum+=money[i%7];
        //     money[i%7]++;
        // }
        // return sum;

        // int ans = 0;       
        // int monday = 1;     
        
        // while (n > 0) {     
        //     for (int day = 0; day < min(n, 7); day++) {  
        //         ans += monday + day; 
        //     }
            
        //     n -= 7;         
        //     monday++;       
        // }
        
        // return ans;

        int ans=0;
        int weeks=n/7;
        int days=n%7;
        ans+=28*weeks+7*(weeks-1)*weeks/2;
        int money=weeks+1;
        ans+=(money*2+days-1)*days/2;
        return ans;
    }
};
