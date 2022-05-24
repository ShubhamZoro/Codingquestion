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
