#include<stdio.h>

struct Poly {
  int coeff;
  int expo;
};

typedef struct Poly poly;

poly p1[10], p2[10], p3[10];

int readPoly(poly p[10]) {
  int t1;
  printf("\nEnter the total number of terms: ");
  scanf("%d", &t1);
  printf("Enter the coefficient and exponent in descending order\n");
  for (int i = 0; i < t1; i++) {
    printf("Coefficient %d: ", i + 1);
    scanf("%d", &p[i].coeff);
    printf("Exponent %d: ", i + 1);
    scanf("%d", &p[i].expo);
  }
  return t1;
}

void displayPoly(poly p[10], int term) {
  for (int k = 0; k < term - 1; k++) {
    printf("%d(x^%d) + ", p[k].coeff, p[k].expo);
  }
  printf("%d(x^%d)", p[term - 1].coeff, p[term - 1].expo);
  printf("\n");
}

int addPoly(poly p1[10], poly p2[10], int t1, int t2, poly p3[10]) {
  int i = 0, j = 0, k = 0;
  while (i < t1 && j < t2) {
    if (p1[i].expo == p2[j].expo) {
      p3[k].coeff = p1[i].coeff + p2[j].coeff;
      p3[k].expo = p1[i].expo;
      i++; j++; k++;
    } else if (p1[i].expo > p2[j].expo) {
      p3[k] = p1[i];
      i++; k++;
    } else {
      p3[k] = p2[j];
      j++; k++;
    }
  }

  while (i < t1) p3[k++] = p1[i++];
  while (j < t2) p3[k++] = p2[j++];

  return k;
}

int main() {
  int t1 = 0, t2 = 0, t3 = 0;

  printf("Enter first polynomial:\n");
  t1 = readPoly(p1);
  printf("First polynomial: ");
  displayPoly(p1, t1);

  printf("Enter second polynomial:\n");
  t2 = readPoly(p2);
  printf("Second polynomial: ");
  displayPoly(p2, t2);

  t3 = addPoly(p1, p2, t1, t2, p3);
  printf("Result of addition: ");
  displayPoly(p3, t3);

  return 0;
}
