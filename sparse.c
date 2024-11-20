#include<stdio.h>
void Sparse(int A[10][10],int m,int n,int s[10][10]){
  int k=1;
  s[0][0]=m;
  s[0][1]=n;
  int i,j;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      if(A[i][j]!=0){//looking for all non zero elements in array A
        s[k][0]=i;//first coloumn as row number
        s[k][1]=j;//second coloumn as coloumn number
        s[k][2]=A[i][j];//finnaly the third coloumn as non zero value
        k++;
      }
    }
  }
  s[0][2]=k-1;
  printf("Tuple form is:\n");
  for(i=0;i<k;i++){
    for(j=0;j<3;j++){
    printf("%d\t",s[i][j]);
    }
    printf("\n");
  }
}
void transpose(int s[10][10]){
 int t[10][10];
  t[0][0] = s[0][1]; // Number of rows in transposed matrix
  t[0][1] = s[0][0]; // Number of columns in transposed matrix
  t[0][2] = s[0][2]; // Number of non-zero elements

  int k = 1;
  for (int i = 0; i < s[0][1]; i++) { // For each column in original matrix
    for (int j = 1; j <= s[0][2]; j++) { // For each non-zero entry
      if (s[j][1] == i) { // If this entry is in the current column
        t[k][0] = s[j][1]; // Column becomes row
        t[k][1] = s[j][0]; // Row becomes column
        t[k][2] = s[j][2]; // Value stays the same
        k++;
      }
    }
}
printf("Transpose of the tuple form is:\n");
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d\t", t[i][j]);
    }
    printf("\n");
  }
}
void main(){
  int s[10][10];
  printf("Enter the number of row and coloumns of matrix:\n");
  int r,c,i,j,A[10][10];
  scanf("%d%d",&r,&c);
  printf("Enter the elements:\n");
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
      scanf("%d",&A[i][j]);
    }
  }
  printf("The matrix is:\n");
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
      printf("%d\t",A[i][j]);
    }
    printf("\n");
  }
  Sparse(A,r,c,s);
  transpose(s);
}