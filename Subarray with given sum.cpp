#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin >>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int j=0,i=0,st=-1,en=0,sum=0;
    while(j<n && sum+arr[j]<=k)
    {
        sum+=arr[j];
        j++;
    }
    if(sum==k)
    {
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    while(j<n){
        sum+=arr[j];
        while(sum>k)
        {
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en<<endl;
    return 0;
}
