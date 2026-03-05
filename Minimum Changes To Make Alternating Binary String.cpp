class Solution {
public:
    int minOperations(string s) {
        string s1="",s2="";

        int n=s.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                s1+="1";
            }
            else{
                s1+="0";
            }

             if(i%2!=0){
                s2+="1";
            }
            else{
                s2+="0";
            }
        }
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=s1[i]){
                count1++;
            }
            if(s[i]!=s2[i]){
                count2++;
            }
        }
        return min(count1,count2);
    }
};

//------------------------------------

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int start_with_0 = 0;
        int start_with_1 = 0;
        
        //010101
        //101010
        for(int i = 0; i<n; i++) {
            if(i%2 == 0) {
                if(s[i] == '0') {
                    start_with_1++;
                } else {
                    start_with_0++;
                }
            } else {
                if(s[i] == '1') {
                    start_with_1++;
                } else {
                    start_with_0++;
                }
            }
        }
        
        return min(start_with_0, start_with_1);
    }
};
