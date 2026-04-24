class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        longest = 0
        this_set = set(nums)

        for num in this_set:
            if (num - 1) not in this_set:
                length = 1
                while (num + length) in this_set:
                    length += 1
                longest = max(length, longest)
        return longest




        