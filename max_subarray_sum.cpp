#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int A[]={12,-23,45,-54,23};
    int n=sizeof(A)/sizeof(A[0]);
        int result=INT_MIN;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans+A[i];
            if(ans<A[i])
                ans=A[i];
            if(result<ans)
                result=ans;
        }
       cout<<result;

}
