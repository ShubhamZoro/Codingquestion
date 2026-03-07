class Solution {
public:
    int minFlips(string s) {
        string snew=s+s;
        string s1="";
        string s2="";
        int n=snew.size();
        int m=s.size();
        for(int i=0;i<n;i++){
            if(i%2!=0){
                s1+="0";
                s2+="1";
            }
            else{
                s1+="1";
                s2+="0";
            }
        }

        int count_s1=0;
        int count_s2=0;

        for(int i=0;i<m;i++){
                if(s[i]!=s1[i]){
                    count_s1++;
                }

                if(s[i]!=s2[i]){
                    count_s2++;
                }
        }
        int res=min(count_s1,count_s2);
       
        for(int i=1;i<=n-m;i++){
            if(snew[i-1]!=s1[i-1]){
                count_s1--;
            }
            if(snew[i+m-1]!=s1[i+m-1]){
                count_s1++;
            }

            if(snew[i-1]!=s2[i-1]){
                count_s2--;
            }
            if(snew[i+m-1]!=s2[i+m-1]){
                count_s2++;
            }

            res=res = min(res, min(count_s1, count_s2));;
        }

        return res;

    }
};
