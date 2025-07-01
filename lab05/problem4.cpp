#include <iostream>

using namespace std;

const int MOD = 9901;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        // 如果指数是奇数，则乘以当前的 base
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        // base 自乘，指数减半
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long sum(long long p, long long n){
    if (n == 0) return 1;
    if (n % 2 == 1) {
        return ( sum(p, n-1) + power(p, n) ) % MOD;
    } else {
        long long m = n/2;
        long long s1 = sum(p, m);       // S(m)
        long long s2 = sum(p, m-1);     // S(m-1)
        long long pm1 = power(p, m+1);  // p^(m+1)
        return ( s1 + pm1 * s2 % MOD ) % MOD;
    }
}

int main()
{
    long long A, B;
    cin >> A >> B;
    if (A == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    else if (B == 0 || A == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    long long result = 1;

    // 对 A 进行质因数分解
    for (long long i = 2; i * i <= A; ++i) {
        if (A % i == 0) {
            long long count = 0;
            // 计算质因子 i 的数量
            while (A % i == 0) {
                count++;
                A /= i;
            }
            // 对于质因子 i, A^B 中它的总指数是 count * B
            // 计算 (1 + i + ... + i^(count*B)) % MOD
            long long term_sum = sum(i, count * B);
            result = (result * term_sum) % MOD;
        }
    }

    // 如果 A 分解后还有剩余, 说明剩余的 A 是一个大于 sqrt(原A) 的质数
    if (A > 1) {
        // 这个质因子的指数是 1, 在 A^B 中总指数是 B
        // 计算 (1 + A + ... + A^B) % MOD
        long long term_sum = sum(A, B);
        result = (result * term_sum) % MOD;
    }

    cout << result << endl;

}