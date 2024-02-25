//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void DFS(vector<int>adj[],int src,vector<bool>&visited,stack<int>&st){
	    visited[src]=true;
	    for(int i:adj[src]){
	        if(!visited[i]){
	            DFS(adj,i,visited,st);
	        }
	    }
	    st.push(src);
	}
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    vector<bool>visited(V,false);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            DFS(adj,i,visited,st);
	        }
	    }
	    vector<int>result;
	    while(!st.empty()){
	        result.push_back(st.top());
	        st.pop();
	    }
	    return result;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {

    if(V!=res.size())
    return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends

// Khans algo-----------------------------------------------------------

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
	    // code here
	    queue<int>que;
	    vector<int>indegree(V,0);
	    for(int u=0;u<V;u++){
	        for(int &v:adj[u]){
	            indegree[v]++;
	        }
	    }

	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            que.push(i);
	        }
	    }

	    vector<int>result;
	    while(!que.empty()){
	        int curr=que.front();
	        result.push_back(curr);
	        que.pop();
	        for(auto i:adj[curr]){
	            indegree[i]--;
	            if(indegree[i]==0){
	                que.push(i);
	            }
	        }
	    }
	    return result;

	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {

    if(V!=res.size())
    return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends

