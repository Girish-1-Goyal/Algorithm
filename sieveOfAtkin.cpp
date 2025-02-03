#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void sieveOfAtkin(int limit) {
    // Step 1: Initialize the sieve array
    vector<bool> is_prime(limit + 1, false);

    // Step 2: Mark potential primes using quadratic forms
    int sqrt_limit = sqrt(limit);
    for (int x = 1; x <= sqrt_limit; ++x) {
        for (int y = 1; y <= sqrt_limit; ++y) {
            int n;

            // Rule 1: 4x^2 + y^2 = n, where n % 12 = 1 or n % 12 = 5
            n = 4 * x * x + y * y;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
                is_prime[n] = !is_prime[n];
            }

            // Rule 2: 3x^2 + y^2 = n, where n % 12 = 7
            n = 3 * x * x + y * y;
            if (n <= limit && n % 12 == 7) {
                is_prime[n] = !is_prime[n];
            }

            // Rule 3: 3x^2 - y^2 = n, where x > y and n % 12 = 11
            n = 3 * x * x - y * y;
            if (x > y && n <= limit && n % 12 == 11) {
                is_prime[n] = !is_prime[n];
            }
        }
    }

    // Step 3: Eliminate non-primes by flipping multiples of squares
    for (int n = 5; n <= sqrt_limit; ++n) {
        if (is_prime[n]) {
            for (int k = n * n; k <= limit; k += n * n) {
                is_prime[k] = false;
            }
        }
    }

    // Step 4: Collect primes
    vector<int> primes;
    if (limit >= 2) primes.push_back(2);
    if (limit >= 3) primes.push_back(3);

    for (int n = 5; n <= limit; ++n) {
        if (is_prime[n]) primes.push_back(n);
    }

    // Step 5: Print the primes
    cout << "Primes up to " << limit << ":\n";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
}

int main() {
    int limit = 100000; // Find primes up to this limit
    sieveOfAtkin(limit);
    return 0;
}