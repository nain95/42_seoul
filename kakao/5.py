import bisect

def interpolate(n, instances, price):
    idx = bisect.bisect_left(instances, n)
    print(idx)


interpolate(200,[1,2,13,16,20],[1,1,1])