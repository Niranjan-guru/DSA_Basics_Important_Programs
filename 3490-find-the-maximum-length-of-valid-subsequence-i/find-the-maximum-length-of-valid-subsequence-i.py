class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        result = 0
        for pattern in [[0,0], [1,0], [0,1], [1,1]]:
            cnt = 0
            for number in nums:
                if number % 2 == pattern[cnt%2]:
                    cnt += 1
            result = max(result, cnt)
        return result


#subpart of the list
# remainder of 2 subsequent elements when / 2 should be equal to the next 2 subsequent