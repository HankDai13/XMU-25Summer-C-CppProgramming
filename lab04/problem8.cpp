#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2000000;
vector<int> primes;
vector<bool> is_prime(MAXN, true);

void getPrimes(int limit) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            if ((int)primes.size() >= limit) break;
            for (int j = 2*i; j < MAXN; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, int>> query(t);
    int maxn = 0;
    for (int i = 0; i < t; ++i) {
        cin >> query[i].first >> query[i].second;
        maxn = max(maxn, max(query[i].first, query[i].second));
    }
    getPrimes(maxn);
    for (int i = 0; i < t; ++i) {
        int n = query[i].first, m = query[i].second;
        if ((primes[n-1] ^ primes[m-1]) == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}