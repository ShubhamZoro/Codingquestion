#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> hist){
    int n=hist.size();
    int ps[n];
    int ns[n];
    int area,ans=-1;
    for(int i=0;i<n;i++)
    {
        ps[i]=-1;
        ns[i]=n;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(hist[i]>hist[j])
            {
                ps[i]=j;
                break;
            }

        }
    }

     for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(hist[i]>hist[j])
            {
                ns[i]=j;
                break;
            }

        }
    }
    for(int i=0;i<n;i++){
        area=(ns[i]-ps[i]-1)*hist[i];
        ans=max(area,ans);
    }
    return ans;
}
int main()
{
    vector<int> s={6, 2, 5, 4, 5, 1, 6};
    cout<<getMaxArea(s);
}
