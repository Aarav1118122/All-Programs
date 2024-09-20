import math
count = 0
sq=0
prime = True
for  i in range(1, 1000001,2):
    sq = int(math.sqrt(i))
    prime = True
    for factor in range(3,sq+1,2):
        if i % factor == 0:
            prime = False
            break
    if prime:
        count+=1

print("No of primes are - ",str(count));
