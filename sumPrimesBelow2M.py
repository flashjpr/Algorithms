sieve = [True] * 2000000

def sign(sieve, n):
    for i in range ( 2 * n , len(sieve), n):
        sieve[i] = False

for i in range (2, int(len(sieve) ** 0.5) + 1):
    if sieve[i] : sign(sieve, i)

print sum(i for i in range(2, len(sieve)) 
	if sieve[i] )