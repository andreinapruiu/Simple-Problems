//Andrei Napruiu 312CA
#include <stdio.h>
#define NMAX 100

// functie de citire a matricei de restrictii(pe linii sau pe coloane)
void read_everything(int n, int a[NMAX][NMAX])
{
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i][0]);
		for (int j = 1; j <= a[i][0]; j++)
			scanf("%d", &a[i][j]);
	}
}

// functie de citire a matricii lui Gigel
void read_matrix(int n, int m, int a[NMAX][NMAX])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
}

// functia de verificare a corectitudinii nomogramei lui Gigel
int verify_lines(int n, int m, int a[NMAX][NMAX], int gigel[NMAX][NMAX])
{
	int k, nr_1;
	for (int i = 0; i < n; i++) {
		k = 1;

		for (int j = 0; j < m; j++) {
			nr_1 = 0;

			while (gigel[i][j] == 0 && j < m)
				j++;

			while (gigel[i][j] == 1 && j < m) {
				nr_1++;
				j++;
			}

			if (nr_1 != 0) {
				if (nr_1 != a[i][k])
					return 0;
				k++;
			}
		}
	}

	return 1;
}

int main(void)
{
	int N, M, grid_lines[NMAX][NMAX], grid_columns[NMAX][NMAX];
	int gigel[NMAX][NMAX], T, ok_lines;

	scanf("%d", &T);
	while (T != 0) {
		scanf("%d", &N);
		scanf("%d", &M);

		read_everything(N, grid_lines);
		read_everything(M, grid_columns);

		read_matrix(N, M, gigel);

		ok_lines = verify_lines(N, M, grid_lines, gigel);

		if (ok_lines == 1)
			printf("Corect\n");
		else
			printf("Eroare\n");

		T--;
	}

	return 0;
}
