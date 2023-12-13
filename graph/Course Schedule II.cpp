class Solution {
public:
     bool bfs(unordered_map<int,vector<int>>graph,int v,vector<int>&indegree,vector<int>&res){
        queue<int>que;
        int count=0;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                que.push(i);
                count++;
            }
        }
        while(!que.empty()){
            int src=que.front();
            res.push_back(src);
            que.pop();
            for(int i:graph[src]){
                indegree[i]--;
                if(indegree[i]==0){
                    que.push(i);
                    count++;
                }

            }
        }
        if(count==v){
            return true;
        }
        res={};
        return false;
     }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>graph;
        vector<int>res;
        vector<int>indegree(numCourses,0);
        for(auto i:prerequisites){
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }  
        bfs(graph,numCourses,indegree,res);
        return res;
    }
};
