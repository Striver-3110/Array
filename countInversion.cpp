#include <iostream>
#include <vector>

using namespace std;

void combine(long long *arr, int l, int mid, int r, long long &inversions) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[i + l];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int j = 0;
    int k = 0;
    int i = l;

    while (j < n1 && k < n2) {
        if (L[j] > R[k]) {
            arr[i++] = R[k++];
            inversions += mid - (j + l) + 1;
        } else {
            arr[i++] = L[j++];
        }
    }

    while (j < n1) {
        arr[i++] = L[j++];
    }
    while (k < n2) {
        arr[i++] = R[k++];
    }
}

void mergeSort(long long *arr, int l, int r, long long &inversions) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid, inversions);
        mergeSort(arr, mid + 1, r, inversions);
        combine(arr, l, mid, r, inversions);
    }
}

long long getInversions(long long *arr, int n) {
    long long inversions = 0;
    mergeSort(arr, 0, n - 1, inversions);
    return inversions;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
s
    long long *arr = new long long[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    long long inversions = getInversions(arr, n);

    cout << "Number of inversions: " << inversions << endl;

    delete[] arr;
    return 0;
}
