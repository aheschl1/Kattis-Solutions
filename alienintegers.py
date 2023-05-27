import sys

num = str(input())
digits = set(num)
first_dig = int(num[0])
if(len(digits) == 10):
    print("Impossible", flush=True)
    sys.exit()

#Closest alien above
above = ""
#Also try adding an extra 10
above_2 = ""

for i in range(first_dig+1, 10):
    if str(i) not in digits:
        above += str(i)
        break

for i in range(1, 10):
    if str(i) not in digits:
        above_2 += str(i)
        break

for i in range(10):
    if str(i) not in digits:
        if len(above) > 0:
            above += str(i)*(len(num)-1)
        above_2 += str(i)*(len(num))
        break

if len(above) == 0 or (int(above) - int(num)) > (int(above_2) - int(num)):
    above = above_2

#Closest bellow
bellow = ""
#Also try dropping a 10
bellow_2 = "0"

for i in range (9, -1, -1):
    if str(i) not in digits:
        bellow_2 += str(i)*(len(num)-1)
        break


for i in range(first_dig-1, -1, -1):
    if str(i) not in digits:
        bellow += str(i)
        break

if len(bellow) > 0:
    for i in range(9,-1, -1):
        if str(i) not in digits:
            bellow += str(i)*(len(num)-1)
            break

if len(bellow) == 0:
    bellow = bellow_2
elif (int(num) - int(bellow)) > (int(num) - int(bellow_2)):
        bellow = bellow_2

#Find best
if len(bellow) == 0 and len(above) > 0:
    print(int(above), flush=True)
elif len(above) == 0 and len(bellow) > 0:
    print(int(bellow), flush=True)
else:
    bellow = int(bellow)
    above = int(above)
    num = int(num)

    if num - bellow < above - num:
        print(bellow, flush=True)
    elif num - bellow > above - num:
        print(above, flush=True)
    else:
        if(bellow == above):
            print(bellow, flush=True)
            sys.exit()
        print(bellow, above, flush=True) if bellow < above else print(above, bellow, flush=True)