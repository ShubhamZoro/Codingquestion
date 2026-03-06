class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int segment=INT_MAX;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1' && segment==INT_MAX){
                segment=i;
                continue;
            }

            if(s[i]=='1' && i>segment+1){
                return false;
            }
            
            if(s[i]=='1' && segment+1==i){
                segment=i;
            }

    
        }
        
        return true;
    }
};
