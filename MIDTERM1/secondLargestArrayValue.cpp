#include <algorithm>

int secondLargest(int arr[],int size) {
    sort(arr,arr+size);
    //cout << arr[0] << arr[1] << endl;
    return arr[size-2];

}
