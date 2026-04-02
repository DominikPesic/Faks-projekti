#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char ime[70];
    int id;
    float prosjek;
};

void addStudents(struct Student* base, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        printf("Enter name: ");
        scanf("%s", base[i].ime);

        printf("Enter student ID: ");
        scanf("%d", &base[i].id);

        printf("Enter grade average: ");
        scanf("%f", &base[i].prosjek);
    }
}

void Savetotxt(struct Student* base, int n) {
    FILE* fp = fopen("studentlist.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return; // Funkcija je void, pa samo radimo return bez broja
    }

    int i;
    for (i = 0; i < n; i++) {
        // ISPRAVAK: fprintf piše u datoteku (fp), ne na ekran
        fprintf(fp, "ID: %d | Name: %s | Average score: %.2f\n",
            base[i].id, base[i].ime, base[i].prosjek);
    }

    fclose(fp);
    printf("\nData successfully saved!\n"); // Ispravljen tipfeler 'prinft'
}

int main() {
    int i, number;
    printf("Enter number of students: ");
    scanf("%d", &number);

    struct Student* mybase = (struct Student*)malloc(number * sizeof(struct Student));

    if (mybase == NULL) {
        printf("Error allocating memory!\n");
        return 1;
    }

    addStudents(mybase, number);
    Savetotxt(mybase, number);

    printf("\n-- ALL STUDENT LIST ON SCREEN --\n");
    for (i = 0; i < number; i++) {
        printf("ID: %d | Name: %s | Average score: %.2f\n",
            mybase[i].id, mybase[i].ime, mybase[i].prosjek);
    }

    free(mybase);
    return 0;
}