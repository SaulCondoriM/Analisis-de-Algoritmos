#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



int partition(vector<int>& v, int low, int high) {
    int pivot = v[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (v[j] < pivot) {
            i++; 
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}



void quickSort(vector<int>& v, int low, int high) {
    if (low < high) {
        
        int pi = partition(v, low, high);

        
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main() {

    vector<int> arr = {10, 7, 8, 9, 1, 5};

    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Array ordenado \n";
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}
