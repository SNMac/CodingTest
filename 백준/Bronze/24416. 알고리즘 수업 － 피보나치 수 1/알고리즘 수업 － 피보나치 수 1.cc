#include <iostream>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
//#define DEBUG

using namespace std;
#ifdef DEBUG
#include <chrono>
using namespace chrono;
#endif

int f[41];
int fib_count;
int fibonacci_count;

int fib(int n) {
    if (n == 1 || n == 2) {
        fib_count++;
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        fibonacci_count++;
    }
    return f[n];
}

int main() {
    FAST_IO
    int n;
    cin >> n;
#ifdef DEBUG
    system_clock::time_point start_time = system_clock::now();
#endif
    fib(n);
    fibonacci(n);
    cout << fib_count << ' ' << fibonacci_count << '\n';
#ifdef DEBUG
    system_clock::time_point end_time = system_clock::now();
    milliseconds mill = duration_cast<milliseconds>(end_time - start_time);
    cout << mill.count() << "ms" << '\n';
#endif
}
