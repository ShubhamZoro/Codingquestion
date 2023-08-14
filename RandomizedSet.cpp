#include <cstdlib>  
class RandomizedSet {
public:
    unordered_map<int,int> m;
vector<int>v;    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // if(umap.find(val)==umap.end()){
        //     umap[val]=list.size();
        //     list.push_back(val);
        //     return true;
        // }
        // return false;
        if(m.count(val))
       return false;
       m[val]=v.size();
       v.push_back(val);
       return true;
    }
    
    bool remove(int val) {
        // if(umap.find(val)!=umap.end()){
        //     int index=umap[val];
        //     int value=list.back();
        //     list[index]=value;
        //    list.pop_back();
        //     umap.erase(val);
        //     return true;
        // }
        // return false;
        if(!m.count(val))
      return false;
      int p=v.back();
      m[p]=m[val];
      v[m[val]]=p;
      v.pop_back();
      m.erase(val);
      return true;
    }
    
    int getRandom() {
        return v[rand()% v.size()];
    }
};
