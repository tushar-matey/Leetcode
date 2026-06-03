class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        lengths = list(map(lambda s: len(s), strs))
        limit=min(lengths)
        ans=""
        for i in range(limit):
            x =strs[0][i]
            for j in strs:
                if j[i]!=x :
                    return ans
            ans+=x
        return ans    