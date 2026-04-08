class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)
            return {};
        deque<int> deq;

        vector<int> result;
        
        for(int i = 0; i<n; i++) {
            //remove the max elements from front which are out of window size
            while(!deq.empty() && deq.front() <= i-k)
                deq.pop_front();
            
            //we maintain the deque in descending order
            while(!deq.empty() && nums[i] > nums[deq.back()])
                deq.pop_back();
            
            deq.push_back(i);

            if(i >= k-1) //Only when the window size first gets equal or greater than k
                result.push_back(nums[deq.front()]); //front will have the max element (dequeue is maintained in descending order)
        }
        return result;
    }
};

////

from typing import List
from collections import deque

def maximums_of_sliding_window(nums: List[int], k: int) -> List[int]:
    dq = deque()  # stores indices
    result = []

    for i in range(len(nums)):
        # Remove indices out of current window
        if dq and dq[0] < i - k + 1:
            dq.popleft()

        # Remove smaller elements from the back
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()

        # Add current index
        dq.append(i)

        # Start adding results when window is valid
        if i >= k - 1:
            result.append(nums[dq[0]])

    return result
