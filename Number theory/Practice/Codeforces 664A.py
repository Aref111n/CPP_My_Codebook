#logic: if A is a natural number, then gcd(A, A+1) is always 1. 

a, b = map(int, input().split())
print(a if a==b else 1)
