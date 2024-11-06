#include <bits/stdc++.h>
using namespace std;

// Shortcuts for data types
#define ll long long
#define pb push_back

// Function to generate prime numbers using the Sieve of Eratosthenes
vector<ll> primeseive(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<ll> primes;
    
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    
    for (ll i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= limit; j += i) {
                is_prime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    for (ll i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.pb(i); // Collecting all prime numbers
        }
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll limit = 5000000; // We want primes up to 5 million
    vector<ll> primes = primeseive(limit); // Generate primes once

    int Q; // Number of queries
    cin >> Q;

    while (Q--) {
        ll K; // The K-th prime to find
        cin >> K;
        cout << primes[K - 1] << '\n'; // Output the K-th prime (1-based index)
    }

    return 0;
}
