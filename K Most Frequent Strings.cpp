from typing import List

def k_most_frequent_strings(strs: List[str], k: int) -> List[str]:
    # Step 1: Count frequency manually
    freq = {}
    for s in strs:
        if s in freq:
            freq[s] += 1
        else:
            freq[s] = 1

    # Step 2: Sort based on (-frequency, string)
    sorted_items = sorted(freq.items(), key=lambda x: (-x[1], x[0]))

    # Step 3: Extract top k strings
    result = []
    for i in range(k):
        if i < len(sorted_items):
            result.append(sorted_items[i][0])

    return result
///


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int, string>> vp;
        unordered_map<string, int> mp;
        
        for(string &word : words) {
            mp[word]++;
        }
        
        for(auto &it : mp) {
            vp.push_back({it.second, it.first});
        }
        
        auto lambda = [](pair<int, string>& p1, pair<int, string>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            
            return p1.first > p2.first;
        };
        
        sort(begin(vp), end(vp), lambda);
        
        int i = 0;
        vector<string> result(k);
        while(i < k) {
            result[i] = vp[i].second;
            i++;
        }
        
        return result;
    }
};
