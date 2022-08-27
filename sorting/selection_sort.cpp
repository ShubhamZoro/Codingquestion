#include<iostream>
using namespace std;
int main()
{
    int a[5]={31,2,1,5,4};
    int n=sizeof(a)/sizeof(a[0]);
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
    for(int i=0;i<n;i++)
        cout<<a[i]<< " " ;
}
