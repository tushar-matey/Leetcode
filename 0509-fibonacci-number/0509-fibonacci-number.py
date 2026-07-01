import numpy as np
class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return n
        
        matrix = np.array([[1, 1], 
                   [1, 0]])

        power = np.linalg.matrix_power(matrix, n-1)

        return power[0][0]