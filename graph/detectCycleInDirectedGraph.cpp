#include <iostream>
#include<unordered_map>
#include<list>
bool checkcycleDFS(int node,unordered_map<int ,bool>&visited,unordered_map<int,bool>&dfsvisited,unordered_map<int,list<int>>&adj){
  visited[node]=true;
  dfsvisited[node]=true;
  for(auto i:adj[node]){
    if(!visited[i]){
      bool cycle=checkcycleDFS(i,visited,dfsvisited, adj);
      if (cycle) {
        return true;
      }
    }
    else if(dfsvisited[i]){
      return true;
    }
  }
  dfsvisited[node]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
 unordered_map<int,list<int>>adj;
 for(int i=0;i<edges.size();i++){
   int u=edges[i].first;
   int v=edges[i].second;
   adj[u].push_back(v);
 }
unordered_map<int ,bool>visited;
unordered_map<int,bool>dfsvisited;
for(int i=0;i<n;i++){
  if(!visited[i]){
    bool cyclefound=checkcycleDFS(i,visited,dfsvisited,adj);
    if(cyclefound){
      return 1;
    }
  }
}
return 0;
}


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        queue<int>que;
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(int u:adj[i]){
                indegree[u]++;
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }

        while(!que.empty()){
            int src=que.front();
            que.pop();
            for(int i:adj[src]){
                indegree[i]--;
                if(indegree[i]==0){
                    que.push(i);
                    count++;
                }
            }
        }
        if(count==V){
            return false;
        }
        return true;
    }
};
