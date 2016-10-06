def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        a = set(nums1)
        b = set(nums2)
        x = a & b
        return list(x) #list
q = [1, 2, 2, 1]
p = [2, 2]
print(intersection(0, q, p))
print(intersection.__doc__)
help(intersection)