#include <iostream>

void insertion_sort(double * a, double * b) {
	for (double * p = a + 1; p < b; ++p) {
		double temp = *p;
		double * temp_p = p;
		while ((temp_p != a) && (*(temp_p - 1) > temp)) {
			*temp_p = *(temp_p - 1);
			--temp_p;
		}
		*temp_p = temp;
	}
}

void bucket_sort(double a[], int n) {
	int * lengths = new int [n];

	for (int i = 0; i < n; ++ i)
		lengths[i] = 0;

	for (int i = 0; i < n; ++ i)
		++lengths[int(a[i] * n)];

	double ** b = new double * [n];
	for (int i = 0; i < n; ++ i)
		b[i] = new double [lengths[i]];

	for (int i = 0; i < n; ++ i)
		lengths[i] = 0;

	for (int i = 0; i < n; ++ i) 
		b[int(a[i] * n)][lengths[int(a[i] * n)]++] = a[i];
	
	for (int i = 0; i < n; ++ i)
		insertion_sort(b[i], b[i] + lengths[i]);
	
	int k = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < lengths[i]; ++j)
			a[k++] = b[i][j];

	delete [] lengths;
	for (int i = 0; i < n; ++i)
		delete [] b[i];
	delete [] b;
}

int main() {
	int len = 0;
	std::cin >> len;
		
	double * arr = new double [len];

	for (int i = 0; i < len; ++i) 
		std::cin >> arr[i];

	bucket_sort(arr, len);

	for (int i = 0; i < len; ++i) 
		std::cout << arr[i] << ' ';
 	std::cout << '\n';

	return 0;
}
