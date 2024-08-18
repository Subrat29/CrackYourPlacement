#include <bits/stdc++.h>
using namespace std;

// tc: nlog(sum of elements in array) or (high−low)
// sc: 1

// Dry run then you get the magic

int countStudents(int n, int arr[], int pages)
{
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // Add pages to the current student
            pagesStudent += arr[i];
        }
        else
        {
            // Assign pages to the next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

long long findPages(int n, int arr[], int m)
{
    if (m > n || m <= 0) // Additional check for m <= 0
        return -1;

    long long low = *max_element(arr, arr + n);   // Minimum possible pages
    long long high = accumulate(arr, arr + n, 0); // Maximum possible pages

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        int studentCount = countStudents(n, arr, mid);

        if (studentCount <= m) // If the number of students needed is <= m
        {
            high = mid - 1; // Try for a smaller `mid` to see if we can still meet the condition
        }
        else // If `studentCount` > `m`, we need to increase `mid`
        {
            low = mid + 1;
        }
    }

    return low; // `low` is the minimum pages that allows the distribution among `m` students
}

int main()
{
    return 0;
}