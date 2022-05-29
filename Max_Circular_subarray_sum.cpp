#include<iostream>
#include<climits>
using namespace std;
//Max subarray sum =Total sum of array-sum of non contributing array
//sum of non contributing array is maximaum subarray sum after changing the array's element sign
int kadane(int arr[],int n)
{
    int result=INT_MIN;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans+arr[i];
        if(ans<arr[i])
        {
            ans=arr[i];
        }
        if(ans>result)
            result=ans;
    }
    return result;
}

int main()
{
    int arr[]={-4,-4,-6,-6,-10,-11,-12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int un_wrap=kadane(arr,n);
    cout<<un_wrap<<endl;
    int wrap_sum=0;
    int total_sum=0;
     int maxsofar=INT_MIN;
        bool allnegative=true;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                allnegative=false;
            else{
                maxsofar = max(maxsofar,arr[i]);
            }
        }


    for(int i=0;i<n;i++)
        total_sum+=arr[i];
    for(int i=0;i<n;i++)
    {
        arr[i]=arr[i]*-1;
    }
    int wrap=kadane(arr,n);
    cout<<wrap<<endl;
    wrap_sum=total_sum+wrap;
     if (allnegative)
    {
        cout<<maxsofar;
        return 0;
    }
    cout<<max(wrap_sum,un_wrap);
    return 0;

}
