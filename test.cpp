#include <iostream>
using namespace std;


int sum67(const int a[], int n);
int main() {
	
	cout << "Change" << endl;
	int n1 = 8;
	int a1[] = { 1, 2, 5, 6, 99, 99, 1, 7 };

	int n2 = 3;
	int a2[] = { 1, 2, 2 };

	int n3 = 7;
	int a3[] = { 1, 2, 2, 6, 99, 99, 7 };

	int n4 = 5;
	int a4 [] = { 1, 1, 6, 7, 2 };
	cout << "Sum: " << sum67(a4, n4);
}

int sum67(const int a[], int n) {
	int sum = 0; 
	for (int i = 0; i < n; i++) {

		if (a[i] == 6) {
			while (a[i] != 7) {
				i++;
			}
		}
		else {
			sum += a[i];
		}
	}
	return sum;

}
