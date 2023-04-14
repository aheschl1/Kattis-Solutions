import math

a, c = input().split()
a = int(a)
c = int(c)
main_num = a*c

primes = []
marked = [0 for _ in range(1000000+2)]
sieve = [i for i in range(2,1000000+1)]

is_perfect = False
root = math.sqrt(main_num)
if math.floor(root) == root:
    is_perfect = True

for num in sieve:
    if marked[num]==0:
        primes.append(num)
        w = num+num
        while w <= sieve[len(sieve)-1]+1:
            marked[w]=1
            w+=num


ded = False
multiplicities={}

for prime in primes:
    if ded:
        break
    while a % prime == 0:
        a //= prime
        if not prime in multiplicities:
            multiplicities[prime]=0
        multiplicities[prime]+=1
        if a == 1:
            ded = True
            break

ded = False
for prime in primes:
    if ded:
        break
    while c % prime == 0:
        c //= prime
        if not prime in multiplicities:
            multiplicities[prime]=0
        multiplicities[prime]+=1
        if c == 1:
            ded = True
            break

ans = 1

for p, r in multiplicities.items():
    ans*=(r+1)

if(is_perfect):
    ans += 1

print(ans)