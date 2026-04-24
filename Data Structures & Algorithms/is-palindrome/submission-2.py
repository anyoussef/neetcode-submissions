class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1
        new = s.lower()

        while i < j:  # fix #2
            if not new[i].isalnum():  # fix #1
                i += 1
                continue
            if not new[j].isalnum():  # fix #1
                j -= 1
                continue

            if new[i] != new[j]:
                return False
            
            i += 1
            j -= 1
        
        return True