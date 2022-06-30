//Andrei Napruiu 312CA
#include <stdio.h>
#define NMAX 100

// functie de citire a elementelor unui vector
void read_vector(int n, int v[NMAX])
{
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
}

// functie de stergere a unui element de pe o pozitie data in vector
void delete_element(int n, int v[NMAX], int k)
{
	for (int i = k; i < n - 1; i++)
		v[i] = v[i + 1];
}

int main(void)
{
	int n, x[NMAX], c[NMAX], p_min, p = 0, nr = 0;

	//toate citirile necesare in rezolvarea problemei
	scanf("%d", &n);
	read_vector(n, x);
	read_vector(n, c);
	scanf("%d", &p_min);

	int all_10 = 1; //cazul special
	for (int i = 0; i < n; i++) {
		if (x[i] != 10)
			all_10 = 0;

		p += x[i] * c[i];
	}

	if (p < p_min && all_10 == 1) {
		printf("-1");
		return 0;
	}

	// stergem toate notele de 10 si punctele de credit aferente lor
	for (int i = 0; i < n; i++) {
		if (x[i] == 10) {
			delete_element(n, x, i);
			delete_element(n, c, i);
			n--;
		}
	}

	int maxim = 0, p_new = 0, pos_max;

	for (int i = 0; i < n; i++) {
		p_new = (10 - x[i]) * c[i];
		if (p_new > maxim) {
			maxim = p_new;
			pos_max = i;
		}
	}

	p += maxim;
	nr++;
	delete_element(n, x, pos_max);
	delete_element(n, c, pos_max);
	n--;

	if (p >= p_min) {
		printf("%d\n", nr);
		return 0;
	}

	while (p < p_min && n != 0) {
		maxim = 0;
		for (int i = 0; i < n; i++) {
			p_new = (10 - x[i]) * c[i];
			if (p_new > maxim) {
				maxim = p_new;
				pos_max = i;
			}
		}

		p += maxim;
		nr++;
		delete_element(n, x, pos_max);
		delete_element(n, c, pos_max);
		n--;

		if (p >= p_min) {
			printf("%d\n", nr);
			return 0;
		}
	}

	return 0;
}
