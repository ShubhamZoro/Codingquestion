class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int max1=INT_MIN;
        int n=colors.size();
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                if(colors[i]!=colors[j]){
                    max1=max(max1,abs(i-j));
                }
                
            }
        }
        return max1;
    }
};

// O(n) 2 pass

class Solution {
public:
    int maxDistance(vector<int>& colors) {
         int n = colors.size();

        int result = 0;

        int i = 0;
        while(colors[i] == colors[n-1]) i++;

        result = max(result, abs(i - (n-1)));

        i = n-1;
        while(colors[0] == colors[i]) i--;

        result = max(result, i);

        return result;
    }
};

// O(n) 1 pass

class Solution {
public:
    int maxDistance(vector<int>& colors) {
      int n = colors.size();

        int result = 0;

       for(int i = 0; i < n; i++) {
            if(colors[i] != colors[0]) {
                result = max(result, i);
            }

            if(colors[i] != colors[n-1]) {
                result = max(result, abs(i - (n-1)));
            }
       }

       return result;
    }
};
