//Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
//There is only one repeated number in nums, return this repeated number.
//You must solve the problem without modifying the array nums and uses only constant extra space.
//Input: nums = [3,1,3,4,2]
//Output: 3
#include<iostream>
using namespace std;
#include<vector>
int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int p=-1;

        vector<int>temp(n,0);
        for(int i=0;i<n;i++)
        {
            temp[nums[i]]++;
        }
        for(int i=0;i<n;i++)
        {
           if(temp[nums[i]]>1)
           {
                p=nums[i];
               break;
           }

        }
        cout<<p;
    }
int main(){
    vector<int> nums;
    int n,p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        nums.push_back(p);
    }
    findDuplicate(nums);
}
