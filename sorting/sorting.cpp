#include<iostream>
using namespace std;
void  bubble_sort(int a[],int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)

        {

            if(a[j+1]<a[j])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }

}

void insertion_sort(int a[],int n)
{
    for(int i=1;i<6;i++)
    {
        int curr=a[i];
        int j=i-1;
        while(j>=0&&a[j]>curr){
                a[j+1]=a[j];
        j=j-1;}
        a[j+1]=curr;
    }
}

void selection_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int mins=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[mins]>a[j])
                mins=j;
        }
        swap(a[mins],a[i]);
    }
}
void count_sort(int a[],int n)
{
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(maxi<a[i])
            maxi=a[i]+1;
    }
    int s[maxi];
    for(int i=0;i<maxi;i++)
        s[i]=0;
    for(int i=0;i<n;i++)
    {
        s[a[i]]=s[a[i]]+1;
    }

    int j=-1;
    for(int i=0;i<maxi;i++)
    {
        if(s[i]>0)
        {
            for(int k=0;k<s[i];k++)
            {
                j++;
                a[j]=i;
            }
        }
    }
}
int main()
{
    int arr[]={1,2,4,3,6,9,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    count_sort(arr ,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<< " ";
}
