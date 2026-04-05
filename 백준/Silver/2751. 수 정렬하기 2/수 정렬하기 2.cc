#include <iostream>

using namespace std;

int* arr;

void swap(int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void max_heap(int parent, int n) {
    while(parent < n) {
        int left = parent * 2 + 1;
        int right = parent * 2 + 2;
        int temp = parent;
        if (left < n) {
            if (arr[left] > arr[temp])
                temp = left;
        }
        if (right < n) {
            if (arr[right] > arr[temp])
                temp = right;
        }
        if (temp == parent)
            break;
        swap(parent, temp);
        parent = temp;
    }
}

void make_heap(int n) {
    for (int i = (n - 1) / 2; i >= 0; i--)
        max_heap(i, n);
}

int main() {
    int n;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    make_heap(n);
    for (int i = n - 1; i > 0; i--) {
        swap(0, i);
        max_heap(0, i);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
    delete[] arr;
}