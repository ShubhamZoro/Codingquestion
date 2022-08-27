#include<iostream>
using namespace std;
int main()
{
    int a[6]={3,5,2,1,6,8};
    for(int i=1;i<6;i++)
    {
        int curr=a[i];
        int j=i-1;
        while(j>=0&&a[j]>curr){
                a[j+1]=a[j];
        j=j-1;}
        a[j+1]=curr;
    }
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<< " ";
    }
}
