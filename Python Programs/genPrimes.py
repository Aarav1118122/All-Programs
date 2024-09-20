def genPrimes():
    primes = [2]
    i = 0
    prime = primes[i] + 1
    while True:
        for nums in primes:
            if ((prime % nums) == 0):
                break
        else:
            primes.append(prime)
            i += 1
            yield primes[i]
        prime += 2


primes = genPrimes()

for i in range(1, 1000):
    print(primes.__next__())
