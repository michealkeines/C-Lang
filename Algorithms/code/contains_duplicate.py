from typing import List

def containsDuplicate(nums: List[int]) -> bool:
    mapping = {}
    for num in nums:
        if num in mapping:
            return True
        else:
            mapping[num] = True

    return False




def testcontainsDuplicate():
    input1: List[int] = [1,2,2,3,4,5]
    input2: List[int] = [1,2,3,4,5]

    assert containsDuplicate(nums=input1) is True
    assert containsDuplicate(nums=input2) is False