#include <iostream>
#include <cmath>

int rank(int a, int d) {
	return (a / int(std::pow(10, d))) % 10;
}

void counting_sort(int a[], int n, int d, int k = 10) {
	int * b = new int [n];
	int * c = new int [k];
	
	for (int i = 0; i < k; ++i)
		c[i] = 0;

	for (int i = 0; i < n; ++i)
		++c[rank(a[i], d)];

	for (int i = 1; i < k; ++i)
		c[i] += c[i - 1];

	for (int i = n - 1; i >= 0; --i) 
		b[--c[rank(a[i], d)]] = a[i];

	for (int i = 0; i < n; ++i)
		a[i] = b[i];

	delete [] b;
	delete [] c;
}

void radix_sort(int a[], int n, int d = 3) {
	for (int i = 0; i < d; ++i)
		counting_sort(a, n, i);
}

int main() {
	int len = 0;
	std::cin >> len;
		
	int * arr = new int [len];

	for (int i = 0; i < len; ++i) 
		std::cin >> arr[i];

	radix_sort(arr, len);

	for (int i = 0; i < len; ++i) 
		std::cout << arr[i] << ' ';
 	std::cout << '\n';

	return 0;
}