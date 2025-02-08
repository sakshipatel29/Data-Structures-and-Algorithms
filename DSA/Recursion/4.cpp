// reverse the array with left and right

#include <iostream>
using namespace std;

void swapArray(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    swap(arr[left], arr[right]);
    swapArray(arr, left + 1, right - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    swapArray(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
