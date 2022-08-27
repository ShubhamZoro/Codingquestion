#include<iostream>
using namespace std;
int main()
{
    int a[7]={5,6,3,2,10,-5,-6};
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7-i-1;j++)

        {

            if(a[j+1]<a[j])
            {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<7;i++)
        cout<<a[i]<< " ";
}
