class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        res = []
        i = 0
        j = 0

        
        while i < m and j < n:
            if nums1[i] > nums2[j]:
                res.append(nums2[j])
                j += 1
            else:
                res.append(nums1[i])
                i += 1

        
        if i < m:
            res.extend(nums1[i:m])
        if j < n:
            res.extend(nums2[j:n])

        
        nums1[:] = res

//o(1) space start filling the biggest element from last 

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i = m - 1
        j = n - 1
        k = m + n - 1

        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

        
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1


            



            
