from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}  # Stores number as key and its index as value
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_map:
                return [num_map[complement], i]
            num_map[num] = i
        return []  # In case no solution is found


sol = Solution()
print(sol.twoSum([2, 7, 11, 15], 9))  # Output: [0, 1]
