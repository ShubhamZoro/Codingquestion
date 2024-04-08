class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count=0;
        int n=students.size();
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int i=0;
        while(!q.empty() &&q.size()>count){
            
            int k=q.front();
             
            if(i<n && k==sandwiches[i] ){   
                i++;
                count=0;
            }
            else{
                q.push(k);
                count++;
            }
            q.pop();
        }
        return q.size();
    }
};
