#include <iostream>
using namespace std;

void InsertionSort(int* A, int length)
{
	int cur;
	for (int i = 1; i < length; i++)
	{
		cur = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] >= cur)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = cur;
		
	}
}

int main()
{
	int n;
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	InsertionSort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;
	return 0;
}