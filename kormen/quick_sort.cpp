#include <iostream>
using namespace std;

int partition ( int A[],int l,int r ) {
	int j = l;
	for (int i=l; i<r; i++)
		if (A[i]<=A[r])
			swap(A[i],A[j++]); 
	swap (A[j], A[r]);
	return j;
}
		
void QS (int A[],int l,int r) {
	if (l<r) {
		int j = partition(A,l,r);
		QS (A,l,j - 1);
		QS(A, j + 1, r);
	}
}

int main() {
	int n;
	cin >> n;

	int * A  = new int [n];
	for(int i = 0; i < n; i++) {
		cin>> A[i];
	}
	
	QS(A, 0, n-1);
	
	for(int i = 0; i < n; i++) {
		cout<<A[i]<<" ";
	}        
	
	return 0;
}
