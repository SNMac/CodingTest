#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* input = new int[n];
    int freq[8001];
    fill_n(freq, 8001, 0);
    double avg = 0;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
        avg += input[i];
        freq[input[i] + 4000]++;
    }
    avg /= n;
    sort(input, input + n);

    int* freqValues = new int[n];
    fill_n(freqValues, n, 4000);
    int freqValuesSize = 0;
    int* max = max_element(freq, freq + 8001);
    freqValues[freqValuesSize] = max - freq - 4000;
    freqValuesSize++;
    while(1) {
        int* temp = max_element(max + 1, freq + 8001);
        if (*temp == *max) {
            freqValues[freqValuesSize] = temp - freq - 4000;
            freqValuesSize++;
            max = temp;
        } else {
            break;
        }
    }

    if (avg < 0.0 && avg > -0.5)
        avg *= -1;
    cout << fixed;
    cout << setprecision(0) << avg << '\n';
    cout << input[n / 2] << '\n';
    if (freqValuesSize == 1) {
        cout << freqValues[0] << '\n';
    } else {
        sort(freqValues, freqValues + n);
        cout << freqValues[1] << '\n';
    }
    cout << input[n - 1] - input[0] << '\n';

    delete[] freqValues;
    delete[] input;
}