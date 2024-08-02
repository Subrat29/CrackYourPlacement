#include <vector>
using namespace std;

// tc: 2*nlogn
// sc: n

int cnt = 0;
void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    // create 2 arrays for copying values
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *first = new int[l1];
    int *second = new int[l2];

    // copy values to first array
    int mainArrayIndex = s;
    for (int i = 0; i < l1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    // copy values to second array
    mainArrayIndex = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while (index1 < l1 && index2 < l2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // copy remaining elements from first array, if any
    while (index1 < l1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    // copy remaining elements from second array, if any
    while (index2 < l2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void countPairs(vector<int> &arr, int s, int mid, int e)
{
    int right = mid + 1;
    for (int left = s; left <= mid; left++)
    {
        while (right <= e && arr[left] > 2 * (long long)arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // sort left part
    mergeSort(arr, s, mid);

    // sort right part
    mergeSort(arr, mid + 1, e);

    // count pairs
    countPairs(arr, s, mid, e);

    // now, merge
    merge(arr, s, e);
}

int reversePairs(vector<int> &arr)
{
    cnt = 0; // reset count for multiple calls
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    return cnt;
}

int main()
{
    return 0;
}