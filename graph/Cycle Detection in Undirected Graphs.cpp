#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
// using BFS
bool isCyclicBFS(int src,unordered_map<int,bool>&visited,unordered_map<int ,list<int>>&adjList){
unordered_map<int,int>parent;
parent[src]=-1;
visited[src]=1;
queue<int>q;
q.push(src);
while(!q.empty()){
    int frontnode=q.front()
    q.pop();
    for(auto i:adjList[frontnode]){
        if(visited[i]==true && parent[frontnode]!=i){
            return true;
        }
        else if(!visited[i]){
           q.push(i);
           visited[i]=1;
           parent[i]=frontnode ;
        }
    }
}
return false
}

string cycleDetection(vector<vector<int>>&edges,int n,int m){
//create adjancecy list
unordered_map<int ,list<int>>adjList;
for(int i=0;i<m;i++){
        int u=edges[i][0];
int v=edges[i][1];
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
unordered_map<int,bool>visited;
// to handle disconnected component
for(int i=0;i<n;i++){
    if(!visited[i]){
        bool ans=isCyclicBFS(i,visited,adjList);
        if(ans==1){
            return "Yes";
        }
    }
}
return "NO";
}


// Using DFS

bool isCyclicDFS(int src,int parent,unordered_map<int,bool>&visited,unordered_map<int ,list<int>>&adjList){
visited[i]=1;
for(auto i:adjList[src]){
    if(!visited[i]){
        bool cycleDetected=isCyclicDFS(i,src,visited,adjList);
        if(cycleDecteted){
            return true;
        }
    }
    else if(i!=parnet){
        return true;
    }
}
return false;
}

string cycleDetection(vector<vector<int>>&edges,int n,int m){
//create adjancecy list
unordered_map<int ,list<int>>adjList;
for(int i=0;i<m;i++){
        int u=edges[i][0];
int v=edges[i][1];
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
unordered_map<int,bool>visited;
// to handle disconnected component
for(int i=0;i<n;i++){
    if(!visited[i]){
        bool ans=isCyclicDFS(i,-1,visited,adjList);
        if(ans==1){
            return "Yes";
        }
    }
}
return "NO";
}
