class MedianFinder {
public:
    vector<int>s;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.push_back(num);
        sort(s.begin(),s.end());
    }
    
    double findMedian() {
        int n=s.size();
        
        if(n%2==0){
            double k=(s[n/2]+s[n/2-1])/2.0;
            return k;
        }
        else{
            double k=s[n/2];
            return k;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
