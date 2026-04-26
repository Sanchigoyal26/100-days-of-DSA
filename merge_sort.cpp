#include <iostream>
using namespace std;

// Merge function
void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp;
    
    int i = left;
    int j = mid + 1;

    // merge two sorted halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // remaining elements
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // copy back
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Merge Sort function
void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}