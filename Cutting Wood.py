from typing import List

def cutting_wood(heights: List[int], k: int) -> int:
    # Write your code here
    sorted(heights,reverse=True)
    max1=max(heights)
    res=0
    for i in range(0,max1+1):
        sum1=0
        for j in heights:
            sum1+=max(0,j-i)
            if(sum1>=k):
                res=i
                break
            
    
    return res;

// Binary Search Approach

from typing import List

def cutting_wood(heights: List[int], k: int) -> int:
    left = 0
    right = max(heights)
    ans = 0

    while left <= right:
        mid = (left + right) // 2
        
        # calculate wood collected
        wood = 0
        for h in heights:
            if h > mid:
                wood += (h - mid)
        
        if wood >= k:
            ans = mid          
            left = mid + 1     
        else:
            right = mid - 1    
    
    return ans
