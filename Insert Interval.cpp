// using extra space

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>temp=intervals;
        temp.push_back(newInterval);
        sort(temp.begin(),temp.end());
        vector<vector<int>>res;
        vector<int>curr=temp[0];
        int n=temp.size();
        int i=1;
        int j=0;
        for(;i<n;i++){
            if(temp[i][0]>curr[1]){
                res.push_back(curr);
                curr=temp[i];
                j=i;
            }
            else{
                curr[0]=min(curr[0],temp[i][0]);
                curr[1]=max(curr[1],temp[i][1]);
            }
        }
        if(i-j==1){
            res.push_back(temp[n-1]);
        }
        else{
            
            res.push_back(curr);
        }
        return res;


    }
};

// optimal sol 

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int i=0;
      vector<vector<int>>result;
      int n=intervals.size();
      while(i<n){
          if(intervals[i][1]<newInterval[0]){
              result.push_back(intervals[i]);
          }
          else if(intervals[i][0]>newInterval[1]){
            break;
          }
          else{
              newInterval[0]=min(newInterval[0],intervals[i][0]);
              newInterval[1]=max(newInterval[1],intervals[i][1]);
          }
          i++;
      }  
      result.push_back(newInterval);
      while(i<n){
          result.push_back(intervals[i]);
          i++;
      }
      return result;
    }
};
        


    }
};
