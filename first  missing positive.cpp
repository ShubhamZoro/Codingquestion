#include <iostream>
#include<vector>
using namespace std;

int main()
{   vector<int> nums;
    nums={3,4,-1,1};
     vector<bool>check(nums.size(),false);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                check[nums[i]-1]=true;
        }
        int i;
        bool flag=true;
        for(i=0;i<check.size();i++)
        {
            if(check[i]!=flag)
                break;

        }
        cout<<i+1;


}
