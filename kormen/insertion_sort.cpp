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

int main() {
	int len = 0;
	std::cin >> len;
		
	double * arr = new double [len];

	for (int i = 0; i < len; ++i) 
		std::cin >> arr[i];

	bucket_sort(arr, arr + len);

	for (int i = 0; i < len; ++i) 
		std::cout << arr[i] << ' ';
 	std::cout << '\n';

	return 0;
}
