class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        freq = {}

        for each in nums:
            if each not in freq:
                freq[each] = freq.get(each, 0) + 1
            else:
                return True


        return False
