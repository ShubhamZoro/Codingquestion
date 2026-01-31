class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int i=0;
        int j=letters.size()-1;
        int res=letters.size();
        while(j>=i){
            int mid=(j+i)/2;
            if(letters[mid]>target){
                res=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        if(res==letters.size()){
           return letters[0]; 
        }
        return letters[res];
    }
};


--------------------------------------------------

  class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int i=0;
        int j=letters.size()-1;
        int res=letters.size();
        while(j>=i){
            int mid=(j+i)/2;
            if(letters[mid]>target){
                res=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        if(res==letters.size()){
           return letters[0]; 
        }
        return letters[res];
    }
};
