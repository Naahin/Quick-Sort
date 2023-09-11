#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int x, int y)
{

	int pivot = arr[x];

	int count = 0;
	for (int i = x + 1; i <= y; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = x + count;
	swap(arr[pivotIndex], arr[x]);


	int i = x, j = y;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int x, int y)
{

	// base case
	if (x >= y)
		return;


	int p = partition(arr, x, y);


	quickSort(arr, x, p - 1);


	quickSort(arr, p + 1, y);
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

