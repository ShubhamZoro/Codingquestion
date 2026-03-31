from typing import List

def local_maxima_in_array(nums: List[int]) -> int:
    # Write your code here
    if(len(nums)<3):
        return 0
    for i in range(1,len(nums)):
        if i==len(nums)-1 and nums[i]>nums[i-1]:
            return i;
        
        if(nums[i]>nums[i-1] and nums[i]>nums[i+1]):
            return i
    return 0
