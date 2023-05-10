def isAnagram(s: str, t: str) -> bool:
    total1 = [0 for x in range(260)]
    total2 = [0 for x in range(260)]

    if (len(s) != len(t)): return False

    for chracter in s:
        h = ord(chracter)
        if total1[h] != 0: 
            total1[h] += 1
        else:
            total1[h] = 1


    for chracter in t:
        v = ord(chracter)
        if total2[v] != 0:
            total2[v] += 1
        else:
            total2[v] = 1

    if len(total1) != len(total2): return False

    for chracter in s:
        t = ord(chracter)
        if total2[t] == 0: return False
        if total1[t] != total2[t]:
            return False

    # print(f"{total1} == {total2}")
    return True

def testisAnagram():
    input1 = "anagram"
    input2 = "nagaram"

    assert isAnagram(input1, input2) is True

    input1 = "ac"
    input2 = "bb"

    assert isAnagram(input1, input2) is False