class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>graph,int v,vector<int>&indegree){
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
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>graph;
        vector<int>indegree(numCourses,0);
        for(auto i:prerequisites){
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }  
                bool cycle=bfs(graph,numCourses,indegree);
                return cycle;
    }
};
