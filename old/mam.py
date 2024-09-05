import random as rand

def findValues(arr, sum, tar):
    print(sum, tar)
    req = sum - tar
    l = len(arr)
    res = []
    
    for i in range(0, l - 1):
        if(req <= 0):
            # print(arr[i])
            res.append(arr[i])
            continue
        v = rand.randint(1,min(req, arr[i] - 1) * 2)
        # v = rand.randint(0,min(req, arr[i] - 1))
        # print(arr[i] - v)
        t = arr[i] - v / 2
        # print(t, v, req)
        res.append(t)
        req -= v / 2
    if(req > 0):
        # print(arr[l-1] - req)
        res.append(arr[l-1] - req)
    else:
        res.append(arr[l-1])
        # print(arr[l-1])
    rand.shuffle(res)
    return res
        
# arr = [2,3,2,2]
# sum = sum(arr)
# tar = 6
# r = findValues(arr, sum, tar)
# print(r)
