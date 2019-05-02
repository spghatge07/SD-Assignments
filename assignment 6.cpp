#include <iostream>
using namespace std;
// Toheapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2
	// If left child is larger than root
	if (l < n &&arr[l] >arr[largest])
		largest = l;
	// If right child is larger than largest so far
	if (r < n &&arr[r] >arr[largest])
		largest = r;
	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}
// main function to do heap sort
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i>= 0; i--)
		heapify(arr, n, i);
	for (int i=n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
int main()
{
int n,arr[100];
	cout<<"Enter the no. of student's marks you want to enter. :\n";
	cin>>n;
	cout<<"Enter the marks :\n";
	for(int i=0;i<n;i++)
    {
cin>>arr[i];
    }
	heapSort(arr, n);
	cout<< "The maximum marks are: "<<arr[n-1]<<"\n";
	cout<<"The minimum marks are: "<<arr[0]<<"\n";
}

