// Recursion
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int t[101][101];
    int solve(string &s1,string &s2,int m,int n){
        if(m==0||n==0){
            return m+n;
        }
        if(t[m][n]!=-1){
            return t[m][n];
        }
        if(s1[m-1]==s2[n-1]){
            return t[m][n]= 1+solve(s1,s2,m-1,n-1);
        }
        else{
            return t[m][n]= 1+min(solve(s1,s2,m-1,n),solve(s1,s2,m,n-1));
        }
        return 0;
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        memset(t,-1,sizeof(t));
        return solve(X,Y,m,n);
    }
};

// Bottom Up
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>>res(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0){
                    res[i][j]=i+j;
                }
                else if(X[i-1]==Y[j-1]){
                    res[i][j]=res[i-1][j-1]+1;
                }
                else{
                    res[i][j]=1+min(res[i-1][j],res[i][j-1]);
                }
            }
        }
        return res[m][n];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
