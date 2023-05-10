from typing import List

def groupAnagrams(strs: List[str]) -> List[List[str]]:
    lookup = {}

    for i in range(len(strs)):
        if (i + 1 == len(strs)):
            break
        for j in range(i +1, len(strs)):
            str1 = strs[i]
            str2 = strs[j]

            if(isanagram(str1, str2)):
                lookup[str1+str2] = True
                lookup[str2+str1] = True



def testgroupanagrams():
    str_list = ["eat","tea","tan","ate","nat","bat"]

    assert [["bat"],["nat","tan"],["ate","eat","tea"]] == groupAnagrams(str_list)
