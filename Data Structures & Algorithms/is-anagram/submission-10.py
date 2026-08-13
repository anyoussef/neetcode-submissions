class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False

        freq = {}

        for i in range(len(s)):
            if s[i] not in freq:
                freq[s[i]] = freq.get(s[i], 0) + 1
            else:
                freq[s[i]] += 1
            if t[i] not in freq:
                freq[t[i]] = freq.get(t[i], 0) + 1
            else:
                freq[t[i]] += 1

        for key, val in freq.items():
            if val < 2:
                return False

        return True

                
        