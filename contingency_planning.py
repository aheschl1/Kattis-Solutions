n = int(input())
curr = n
i = 1

total = 0

while total < 1e9:
    total += curr
    curr *= (n-i)
    i+=1
    if i > n and total < 1e9:
        print(total)
        exit()

print("JUST RUN!!")
