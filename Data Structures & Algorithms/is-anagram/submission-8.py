class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False
        
        counts = {}

        for each in s:
            if each not in counts:
                counts[each] = 1
            else:
                counts[each] += 1
        
        for each in t:
            if each in counts:
                counts[each] -= 1
            else:
                return False

        for value in counts.values():
            if value != 0:
                return False

        return True