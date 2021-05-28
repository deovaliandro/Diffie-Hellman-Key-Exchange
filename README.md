# Diffie-Hellman Key Exchange

## Properties

1. n, a prime number (not secret)
2. g, primitive root of n (not secret)
3. x and y, random number by Alice and bob
4. k0, k1, the secret key

Result:

- Alice's key: private key = x, publick key = (X, g, n)
- Bob's key: private key = y, publick key = (Y, g, n)

usage:

```bash
g++ diffie-hellman.cpp -o diffie-hellman
./diffie-hellman
```