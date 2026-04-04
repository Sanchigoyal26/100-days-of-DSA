#include <iostream>
#include <vector>
using namespace std;

bool isMinHeap(vector<int>& arr, int n) {
    
    for(int i = 0; i <= (n - 2) / 2; i++) {

        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[i] > arr[left])
            return false;

        if(right < n && arr[i] > arr[right])
            return false;
    }

    return true;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(isMinHeap(arr, n))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}