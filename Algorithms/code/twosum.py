from typing import List

def twoSum(nums: List[int], target: int) -> List[int]:
    #nums.sort()
    print(nums)
    start = 0
    end = len(nums) - 1
    
    lookup = {}
    # x + y = target

    for i in range(len(nums)):
        val = nums[i]
        lookup[val] = i
    
    for i in range(len(nums)):
        x = nums[i]
        y = target - x
        print(f"{y} = {target} - {x}")
        if y in lookup and lookup[y] != i:
                return [i, lookup[y]]



def testTwoSum():
    input1 = [2,7,11,15]
    target1 = 9

    assert [0, 1] == twoSum(input1, target1)

    input1 = [3,2,4]
    target1 = 6

    assert [1, 2] == twoSum(input1, target1)

    input1 = [3,3]
    target1 = 6

    assert [0, 1] == twoSum(input1, target1)