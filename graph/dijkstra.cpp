
#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
  vector<int>dist(edges.size(),INT_MAX);
  set<pair<int,int>>st;
  dist[start]=0;
  st.insert({0,start});
  while(!st.empty()){
    auto top=*(st.begin());
    int distnode=top.first;
    int topnode=top.second;
    st.erase(st.begin());
    for(auto neigh:edges[topnode]){
      if(distnode+neigh[1]<dist[neigh[0]]){
        auto record=st.find({dist[neigh[0]],neigh[0]});
        if(st.end()!=record){
          st.erase(record);
        }
        dist[neigh[0]]=distnode+neigh[1];
        st.insert({dist[neigh[0]],neigh[0]});
      }
    }
  }
  for(int i=0;i<dist.size();i++){
    if(dist[i]==INT_MAX){
      dist[i]=-1;
    }
  }
  return dist;
}
