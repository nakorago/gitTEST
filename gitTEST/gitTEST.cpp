#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>

#define maxNUM 100
#define MAXINT 2147483640
using namespace std;

void GenRandAry(int *ary, int N)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i <= N; i++)
	{
		ary[i] = (rand() % maxNUM) + 1;
		cout << ary[i] << " ";
	}
	cout << endl;
}

void solver(int **test, int *ary, int N)
{
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			test[i][j] = 0;
		}
	}

	for (int len = 2; len <= N; len++)
	{
		for (int i = 1; i <= (N - len + 1); i++)
		{
			int j = i + len - 1;
			test[i][j] = MAXINT;

			for (int k = i; k <= (j - 1); k++)
			{

				int q = (test[i][k] + test[k + 1][j]) + (ary[i - 1] * ary[k] * ary[j]);

				if (q < test[i][j])
				{
					test[i][j] = q;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << test[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int N = 0;
	cin >> N;
	int *ary = new int[N + 1];
	int **test = new int *[N + 1];

	for (int i = 0; i <= N; i++)
	{
		test[i] = new int[N + 1];
	}

	GenRandAry(ary, N);
	solver(test, ary, N);


	cout << "optimal solution: " << test[1][N] << endl;

	cin >> N;
	return 0;
}