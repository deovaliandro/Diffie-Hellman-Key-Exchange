#include <iostream>
#include <math.h>

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
    int h[prime-1];
    int hprime = prime;

    for(int i=0; i<prime; i++) {
        h[i] = pow(root, i+1);
    }

    for(int i=0; i<sizeof(h)/sizeof(h[0]); i++) {
        for (int j=0; j<sizeof(h)/sizeof(h[0]); j++) {
            if (h[i] == h[j]) {
                std::cout << "Not primite root" << std::endl;
                break;
            }
        }

        if(isRelativePrime(prime, h[i]) != 1) {
            std::cout << "Not primite root" << std::endl;
            break;
        }
    }

    return 1;
}

int main() {
    int n, g, x, y, k0, k1;

    std::cin >> n >> g;

    if(isPrimitiveRoot(n, g) == 1) {
        
    } else {
        std::cout << g << " is not primite root from " << n << std::endl;
    }
}