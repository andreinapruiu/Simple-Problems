//Andrei Napruiu 312CA
#include <stdio.h>
#define NMAX 100

// functie de creare a numarului cu cifrele ordonate descrescator

int sort_high_to_low(int N)
{
	int v[10];

	int dim = 0;
	while (N != 0) {
		v[dim++] = N % 10;
		N /= 10;
	}

	for (int i = 0; i < dim - 1; i++) {
		for (int j = i + 1; j < dim; j++) {
			if (v[i] < v[j]) {
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}

	int new_N = 0;
	for (int i = 0; i < dim; i++)
		new_N = new_N * 10 + v[i];

	return new_N;
}

// functie de creare a numarului cu cifrele ordonate crescator
// folosesc functia pentru a oglindi numarul cu cifrele ordonate descrescator,
// astfel obtin numarul necesar

int mirrored(int N)
{
	int inv = 0;

	while (N != 0) {
		inv = inv * 10 + N % 10;
		N /= 10;
	}

	return inv;
}

int main(void)
{
	int N, n_descrescator, n_crescator, V[NMAX], DIM = 0, ok = 0, new_N;
	int k, m, left, right;
	scanf("%d", &N);

	// salvam in 2 variabile cu nume sugestive numarul N ordonat crescator
														// si descrescator

	n_descrescator = sort_high_to_low(N);
	n_crescator = mirrored(n_descrescator); // oglinditul lui N ordonat
											// descrescator va fi mereu N
											// ordonat crescator
											// (cu eliminarea cifrelor de 0)

	k = 0;

	// iteram pana se gaseste un numar identic cu altul din vector
	while (ok == 0) {
		new_N = n_descrescator - n_crescator; // numarul cerut
		k++; //numarul de numere de pana acum
		V[DIM++] = new_N; //adaugarea noului numar in vector

		/*dupa fiecare adaugare parcurgem vectorul pentru a stabili daca
			exista deja in vector un alt element egal cu ultimul adaugat*/
		for (int i = 0; i < DIM - 1; i++) {
			if (V[i] == new_N) {
				ok = 1;

				left = i;
				right = k - 1;
				m = right - left;

				k = k - m - 1;

				break;
			}
		}
		//in caz afirmativ if-ului de sus salvam datele necesare pentru afisare

		n_descrescator = sort_high_to_low(new_N);
		n_crescator = mirrored(n_descrescator);
	}

	printf("%d\n", k);
	for (int i = left; i < right; i++)
		printf("%d ", V[i]);
	printf("\n");

	return 0;
}
