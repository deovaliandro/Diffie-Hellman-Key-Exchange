#include <iostream>
#include <math.h>

int powmod(int a, int b, int n) {
    int result = a;
    
    for(int i=0; i<b-1; i++) {
        result = (result * a) % n;
    }

    return result;
}

int isRelativePrime(int a, int b) {
    int dummy;

    while (b != 0) {
        dummy = a % b;
        a = b;
        b = dummy;
    }

    return a;    
}

int isPrimitiveRoot(int prime, int root) {
    int h[prime-2];
    int hprime = prime;

    for(int i=0; i<prime; i++) {
        h[i] = powmod(root, i+1, prime);
        // std::cout << h[i] << std::endl;
    }
    
    int kampret = 1;

    for(int i=0; i<sizeof(h)/sizeof(h[0]) - 1; i++) {
        for (int j=kampret; j<sizeof(h)/sizeof(h[0]); j++) {
            // std::cout << h[i] << "=" << h[j] << std::endl;
            if (h[i] == h[j]) {
                std::cout << i << " " << j << " " << h[i] << " " << h[j] << std::endl;
                std::cout << "Not primite root" << std::endl;
                return 0;
            }
        }
            kampret++;

        if(isRelativePrime(prime, h[i]) != 1) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n, g = 1, x = 1, y = 1, k0, k1, X, Y;

    std::cin >> n >> g >> x >> y;

    if(isPrimitiveRoot(n, g) == 1) {

        X = powmod(g, x, n);
        Y = powmod(g, y, n);

        k0 = powmod(Y, x, n);
        k1 = powmod(X, y, n);

        if (k0 == k1) {
            std::cout << "Key same " << k0 << std::endl;
        } else {
            std::cout << "Key not same" << std::endl;
        }
        
    } else {
        std::cout << g << " is not primite root from " << n << std::endl;
    }
}