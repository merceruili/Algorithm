#include <iostream>
#include <algorithm>
#include "SortHelper.h"

using namespace std;

template <typename T>
void quickSort1(T arr[], int l, int r) {
	if (l > r) return;
	int k = l;
	T base = arr[k];
	for (int i = l+1; i <= r; i++) {
		if (arr[i]<base)
			swap(arr[++k], arr[i]);
	}
	swap(arr[l], arr[k]);
	quickSort1(arr, l, k - 1);
	quickSort1(arr, k + 1, r);
}

template <typename T>
void quickSort2(T arr[], int l, int r) {
	if (l>r) return;
	int i = l, j = r+1;
	T base = arr[l];
	while (true){
		while (i<r&&arr[++i] <= base);
		while (j>l&&arr[--j] >= base);
		if (i < j) {
			swap(arr[i], arr[j]);
		} else {
			break;
		}
	}
	swap(arr[l], arr[j]);
	quickSort2(arr, l, j - 1);
	quickSort2(arr, j + 1, r);
}

/*lt:less than, gt: great than
  (l,lt)<base (gt,r)>base
*/
template <typename T>
void quickSort3(T arr[], int l, int r) {
	if (l > r) return;
	int lt = l, gt = r + 1, i=l+1;
	T base = arr[l];
	while( i<gt ) {
		if (arr[i] < base) {
			swap(arr[i], arr[++lt]);
			i++;
		}else if (arr[i] > base)
			swap(arr[i], arr[--gt]);
		else i++;
	}
	swap(arr[l], arr[lt]);
	quickSort3(arr, l, lt-1);
	quickSort3(arr, gt, r);
}

int main() {


	//system("calc");

	int n = 1000000;
	int* arr1 = SortHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortHelper::generateRandomArray(n, 0, n);
	int* arr3 = SortHelper::generateRandomArray(n, 0, n);

	//int arr1[] = { 58,47,99,35,47,33,489,47,47,45 };
	
	SortHelper::testSort("quickSort1", quickSort1, arr1, 0, n);
	SortHelper::testSort("quickSort2", quickSort2, arr2, 0, n);
	SortHelper::testSort("quickSort3", quickSort3, arr3, 0, n);

}