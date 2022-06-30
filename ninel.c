//Andrei Napruiu 312CA
#include <stdio.h>

int main(void)
{
	long N, S = 0, xmax_impar, xmin_par, tree1, tree2, tree3;
	long specials_number;
	double m_a;

	scanf("%ld", &N);

	specials_number = 0;
	xmax_impar = 0;
	xmin_par = -1;

	if (N == 1 || N == 2) {
		printf("%ld\n", S);

		m_a = 0;
		printf("%.7lf\n", m_a);

		printf("%ld\n", xmax_impar);

		xmin_par = 0;
		printf("%ld\n", xmin_par);

		return 0;
	}

	scanf("%ld", &tree1);
	scanf("%ld", &tree2);
	scanf("%ld", &tree3);

	if (tree2 > tree1 && tree2 > tree3) {
		S += tree2;
		specials_number++;

		if (xmax_impar < tree2)
			xmax_impar = tree2;
	}

	for (int i = 3; i < N; i++) {
		tree1 = tree2;
		tree2 = tree3;
		scanf("%ld", &tree3);

		if (tree2 > tree1 && tree2 > tree3) {
			S += tree2;
			specials_number++;

			if ((i - 1) % 2 == 0) {
				if (xmin_par == -1)
					xmin_par = tree2;

				if (xmin_par > tree2)
					xmin_par = tree2;
			} else {
				if (xmax_impar < tree2)
					xmax_impar = tree2;
			}
		}
	}

	m_a = (double)S / specials_number;
	printf("%ld\n", S);
	printf("%.7lf\n", m_a);
	printf("%ld\n", xmax_impar);
	printf("%ld\n", xmin_par);

	return 0;
}
