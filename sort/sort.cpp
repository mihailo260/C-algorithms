#include<stdio.h>
#include<stdlib.h>

void SelectionSort(int arr[],int len) {
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i + 1; j < len; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void BubbleSort(int arr[], int len){
	for (int i = 0; i < len-2; i++)
	{
		for (int j =0; j < len-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void InsertionSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}
void printArr(int arr[], int len) {
	
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}
void merge(int arr[], int left[],int right[],int len, int lenL,int lenR) {
	int i = 0, j = 0, z = 0;
	while(i < lenL && j < lenR){
		if (left[i] < right[j]) {
			arr[z] = left[i];
			i++;
			
		}
		else {
			arr[z] = right[j];
			j++;
			
		}
		z++;
	}
	while (i < lenL) {
		arr[z] = left[i];
		i++;
		z++;
	}
	while (j < lenR) {
		arr[z] = right[j];
		j++;
		z++;
	}

}
void mergeSort(int arr[], int len) {
	if (len <= 1) {
		return;
	}
	int mid = len / 2;
	int lenL = mid;
	int lenR = len - mid;
	int* left = (int*)malloc(lenL * sizeof(int));
	int* right = (int*)malloc(lenR * sizeof(int));
	for (int i = 0; i < lenL; i++) {
		left[i] = arr[i];
	}
	for (int i = 0; i < lenR; i++) {
		right[i] = arr[mid + i];
	}

	mergeSort(left, lenL);
	mergeSort(right, lenR);
	merge(arr, left, right,len,lenL,lenR);
	free(left);
	free(right);

}
int partitioning(int arr[], int startIndex, int endIndex) {
	int pivot = arr[endIndex];
	int pivotIndex = startIndex;
	for (int i = startIndex; i < endIndex; i++)
	{
		if (arr[i] <  pivot) {
			if (i != pivotIndex) {
				int temp = arr[i];
				arr[i] = arr[pivotIndex];
				arr[pivotIndex] = temp;
			}
			pivotIndex++;
		}

	}
	arr[endIndex] = arr[pivotIndex];
	arr[pivotIndex] = pivot;
	return pivotIndex;

}
void quickSort(int arr[], int startIndex, int endIndex){

	if (startIndex >= endIndex) {
		return;
	}
	int pivotIndex = partitioning(arr, startIndex, endIndex);
	quickSort(arr, pivotIndex+1, endIndex);
	quickSort(arr, startIndex, pivotIndex-1);
}
void heapify(int arr[],int n) {
	int p1;
	int p2;
	int r;
	int p;
	for (int i = (n/2)-1; i >= 0; i--)
	{
		r = i;
		p1 = 2 *r+1;
		p2 = 2 * r + 2;
		if (p2 > n - 1) {
			p = p1;
		}else if(arr[p1] > arr[p2]) {
			p = p1;
		}
		else {
			p = p2;
		}
		while(p < n && arr[p] > arr[r]) {
			int temp = arr[p];
			arr[p] = arr[r];
			arr[r] = temp;
			r = p;
			p1 = 2 * r + 1;
			p2 = 2 * r + 2;
			if (p2 > n - 1) {
				p = p1;
			}
			else if (arr[p1] > arr[p2]) {
				p = p1;
			}
			else {
				p = p2;
			}
		}
	}
}
void heapSort(int arr[], int n) {
	heapify(arr, n);
	int temp;
	int p1;
	int p2;
	int p;
	int r;
	for (int i = 0; i < n; i++)
	{
		temp = arr[n - i - 1];
		arr[n - i - 1] = arr[0];
		arr[0] = temp;
		r = 0;
		p1 = 2 * r + 1;
		p2 = 2 * r + 2;
		if (p2 >= n -i-1) {
			p = p1;
		}
		else if(arr[p1] > arr[p2]) {
			p = p1;
		}
		else {
			p = p2;
		}
		while (p < n-(i+1) && arr[p] > arr[r]) {
			temp = arr[p];
			arr[p] = arr[r];
			arr[r] = temp;
			r = p;
			p1 = 2 * r + 1;
			p2 = 2 * r + 2;
			if (p2 >= n - i - 1) {
				p = p1;
			}
			else if (arr[p1] > arr[p2]) {
				p = p1;
			}
			else {
				p = p2;
			}

		}

	}
}
int main() {
	int arr[] = { 1,2,7,0,8,4,9,5 };
	int len = sizeof(arr) / sizeof(int);
	/*SelectionSort(arr,len);*/
	/*BubbleSort(arr, len);*/
	/*InsertionSort(arr, len);*/
	/*mergeSort(arr,len);*/
	
	/*quickSort(arr, 0, len-1);*/
	heapSort(arr, len);
	printArr(arr, len);

}