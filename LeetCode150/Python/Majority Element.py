class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n=len(nums)
        m=nums[0]
        i=1
        for j in range(1,n):
            if(nums[j]==m):
                i+=1
            else:
                i-=1
            
            if(i==0):
                i=1
                m=nums[j]
            
        return m
