class Solution {
public:
    string invert_str(string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
        }
        return s;
    }
    char findKthBit(int n, int k) {
        if(k==1){
            return '0';
        }
        string s="0";
        vector<string>invert(n+1);
        invert[0]="1";
        for(int i=1;i<n;i++){
            string p=invert[i-1];
            reverse(p.begin(),p.end());
            s=s+"1"+p;
            invert[i]=invert_str(s);
        }
        return s[k-1];
    }

};
