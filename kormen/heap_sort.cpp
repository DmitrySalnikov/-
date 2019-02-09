#include <iostream>

void swap(int & a, int & b) {
	int temp = a;
	a = b;
	b = temp;
}

void sift_down(int arr[], int size, int i = 0) 
{
	while (2 * i + 1 < size)
		if (2 * i + 2 < size) 
		{
			if ((arr[i] < arr[2 * i + 1]) || (arr[i] < arr[2 * i + 2])) 
			{
				if (arr[2 * i + 1] >= arr[2 * i + 2]) 
				{
					swap(arr[2 * i + 1], arr[i]);
					i = 2 * i + 1;
				}
				else {
					swap(arr[2 * i + 2], arr[i]);
					i = 2 * i + 2;
				}
			}
			else
				break;
		}
		else {
			if (arr[i] < arr[2 * i + 1]) {
				swap(arr[i], arr[2 * i + 1]);
				i = 2 * i + 1;
			}
			else
				break;
		}
}

void delete_head(int arr[], int size) {
	swap(arr[0], arr[size - 1]);
	sift_down(arr, size - 1);
}

void build_max_heap(int arr[], int size) {
	for (int i = (size - 1) / 2; i >=0; --i)
		sift_down(arr, size, i);
}

void heap_sort(int arr[], int size) {
	for (int i = 0; i < size - 1; ++i)
		delete_head(arr, size - i);
}

int main() {
	int len = 0;
	std::cin >> len;
		
	int * arr = new int [len];

	for (int i = 0; i < len; ++i) 
		std::cin >> arr[i];

 	build_max_heap(arr, len);

 	heap_sort(arr, len);

	for (int i = 0; i < len; ++i) 
		std::cout << arr[i] << ' ';
 	std::cout << '\n';

	return 0;
}
