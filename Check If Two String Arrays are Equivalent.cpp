class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1=word1[0];
        string w2=word2[0];

        for(int i=1;i<word1.size();i++){
            w1=w1+word1[i];
        }
        for(int i=1;i<word2.size();i++){
            w2=w2+word2[i];
        }
        if(w1==w2){
            return true;
        }
        return false;
    }
};
