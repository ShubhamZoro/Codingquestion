class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        i=prices[0]
        m=-1
        for j in range(1,n):
            i=min(prices[j],i)
            m=max(m,prices[j]-i)
        
        if(m<0):
            return 0
        return m
