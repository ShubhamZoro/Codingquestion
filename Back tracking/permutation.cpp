#include<iostream>
#include<string>
using namespace std;

void permute(char arr[],int l, int r)
{
    int i;
    if(l==r)
    {
        cout<<arr<<endl;

    }
    else{
        for(i=l;i<=r;i++){
            swap(arr[i],arr[l]);
            permute(arr,l+1,r);
            swap(arr[i],arr[l]);
        }
    }

}

int main(){
    char str[]="abcd";
    int n=4;
    permute(str,0,n-1);
}
