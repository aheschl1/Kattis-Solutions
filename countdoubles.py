from sys import stdin

_, m = stdin.readline().split(' ')
m = int(m)
array = stdin.readline().split(' ')

start = 0
end = m-1
evens = sum([1 for x in array[start:end+1] if int(x)%2 == 0])

if evens >= 2:
    total = 1
else:
    total = 0

while end < len(array)-1:
    start += 1
    end += 1
    if int(array[start - 1])%2 == 0:
        evens -= 1
    if int(array[end])%2 == 0:
        evens += 1
    if evens >= 2:
        total += 1

print(total)