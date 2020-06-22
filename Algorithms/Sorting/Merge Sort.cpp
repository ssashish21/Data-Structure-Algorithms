// Merge sort: O(NlogN)

#include <iostream>
#include<vector>
using namespace std;

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] <<" ";
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    k--;
    while (k >= 0)
    {
        arr[k + low] = temp[k];
        k--;
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    vector<int> arr = {1,5,59,8,7,84,87,62,8,41,7,85,48,4};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    printArray(arr, n);
    return (0);
}