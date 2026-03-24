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

