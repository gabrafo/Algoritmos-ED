import math

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        for x in nums2:
            nums1.append(x)
        nums1.sort()
        
        if len(nums1)%2 != 0:
            return nums1[int(len(nums1)/2)]

        return (nums1[math.floor(len(nums1) / 2) - 1] + nums1[math.ceil(len(nums1) / 2)])/2
