#include <stdio.h>

int main() {

	int i;
	int broj;
	int niz[100] = { 0 };
	int dekada[5] = { 0 };
	printf("Unesite brojeve izmedu 50 i 99\n");
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &niz[i]);
		if (niz[i] < 50 || niz[i]>99) {
			printf("Krivi broj je unesen.");
			return 0;
		}
		else {
			int d = (niz[i] - 50) / 10;
			dekada[d]++;
		}
	}

	
	int m = 0;
	int md = 0;

	for (i = 0; i < 5; i++) {
		if (dekada[i] > m) {
			m = dekada[i];
			md = i;
		}
	}

	printf("Najbrojnija dekada je %d:\n", md+5);
	for (i = 0; i < 10; i++) {
		int d = (niz[i] - 50) / 10;
		if (d == md) {
			printf("%d\n", niz[i]);
		}
	}
}