class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        counts = {}

        for each in nums:
            if each in counts:
                counts[each] += 1
            else:
                counts[each] = 1

        for each in counts:
            if counts[each] > 1:
                return True

        return False
        