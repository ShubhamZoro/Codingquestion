from typing import List

class SumBetweenRange:
    def __init__(self, nums: List[int]):
        self.nums=nums
        self.prefix_sum=[]
        sum1=0
        for i in nums:
            sum1+=i
            self.prefix_sum.append(sum1)

    def sum_range(self, i: int, j: int):
        sum1=0
        sum1=self.prefix_sum[j]
        if(i==0):
            return sum1
        
        else:
            sum1-=self.prefix_sum[i-1]
        
        return sum1
