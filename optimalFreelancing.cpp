using namespace std;
bool cmp(unordered_map<string,int> job1,unordered_map<string,int> job2){
  return job1.begin()->second>job2.begin()->second;
}

int updateWeek(int deadline,int pay,vector<int>&week,int &count){
  for(int i=deadline; i>0;i--){
    if(!week[i]){
      week[i]=1;
      count++;
      return pay;
    }
  }
  return 0;
}

int optimalFreelancing(vector<unordered_map<string, int>> jobs) {
 vector<int>week(8,0);
  int countDays=0;
  int maxProfit=0;
  sort(jobs.begin(),jobs.end(),cmp);
  for(auto job:jobs){
    int deadline=job["deadline"];
    int payment=job["payment"];
    if(deadline>7){
      deadline=7;
    }
    maxProfit+=updateWeek(deadline,payment,week,countDays);
    if(countDays==7) break;
  }
  return maxProfit;
}
