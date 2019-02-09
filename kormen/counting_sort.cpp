#include <iostream>

void counting_sort(int a[], int n, int k = 6) {
	int * b = new int [n];
	int * c = new int [k];
	
	for (int i = 0; i < k; ++i)
		c[i] = 0;

	for (int i = 0; i < n; ++i)
		++c[a[i]];

	for (int i = 1; i < k; ++i)
		c[i] += c[i - 1];

	for (int i = n - 1; i >= 0; --i) 
		b[--c[a[i]]] = a[i];

	for (int i = 0; i < n; ++i)
		a[i] = b[i];

	delete [] b;
	delete [] c;
}

int main() {
	int len = 0;
	std::cin >> len;
		
	int * arr = new int [len];

	for (int i = 0; i < len; ++i) 
		std::cin >> arr[i];

 	counting_sort(arr, len);

	for (int i = 0; i < len; ++i) 
		std::cout << arr[i] << ' ';
 	std::cout << '\n';

	return 0;
}
