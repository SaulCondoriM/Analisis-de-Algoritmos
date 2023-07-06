#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& v, int low, int high, int x) {

    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (v[mid] == x)
            return mid;

        if (v[mid] > x)
            return binarySearch(v, low, mid - 1, x);

        return binarySearch(v, mid + 1, high, x);
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};

    int x = 10;

    int n = arr.size();

    int result = binarySearch(arr, 0, n - 1, x);
    
    if(result == -1)
        cout<< "NO esta en el array";
    else
        cout<< "SI esta, en el indice: " << result;
    return 0;
}
