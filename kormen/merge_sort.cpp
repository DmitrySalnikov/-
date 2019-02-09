#include <iostream>
#include <climits>	// int INT_MAX = 23131314414;

void merge(int a[], int p, int q, int r) 
{
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int * l = new int [n1 + 1];
	int * R = new int [n2 + 1];

	for (int i = 0; i < n1; ++i)
		l[i] = a[p + i];
	for (int i = 0; i < n2; ++i)
		R[i] = a[q + i + 1];
	l[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i = 0;
	int j = 0;
	for (int k = p; k <= r; ++k)
		if (l[i] <= R[j]) {
			a[k] = l[i];
			++i;
		}
		else {
			a[k] = R[j];
			++j;
		}

	delete [] R;
	delete [] l;
}

void merge_sort(int a[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

int main() {
	int len = 0;
	std::cin >> len;
		
	int * arr = new int [len];

	for (int i = 0; i < len; ++i) 
		std::cin >> arr[i];

 	merge_sort(arr, 0, len - 1);

	for (int i = 0; i < len; ++i) 
		std::cout << arr[i] << ' ';
 	std::cout << '\n';

	return 0;
}
