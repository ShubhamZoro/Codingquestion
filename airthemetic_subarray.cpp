//A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same
//Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
//Output: [true,false,true]
//Explanation:
//In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
//In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
//In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.
//Leetcode airthmetic subarray problem
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main()

{   int nums[] = {4,6,5,9,3,7}, l[] = {0,0,2}, r[] = {2,3,5};
    int n=sizeof(nums)/sizeof(nums[0]);
        vector<bool> res;
        vector<int> temp;

        for(int i=0;i<n;i++)
        {
            bool flag=true;
            temp.clear();
            for(int j=l[i];j<=r[i];j++)
            {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            int diff=temp[0]-temp[1];
            for(int j=0;j<temp.size()-1;j++)
            {
                 int p=temp[j]-temp[j+1];
                if(diff!=p)
                {
                    flag=false;
                    break;
                }

            }

                 res.push_back(flag);
                    temp.clear();

        }
       cout<<res[0];


}
