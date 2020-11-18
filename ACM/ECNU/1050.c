#include <stdio.h>
void fun(){
    /*
     * O(n^3)
     * */
    int N, n;
    int arr1[100][100];
    int arr2[100][100];
    int arr3[100][100];
    scanf("%d", &N);
    while (N--){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &arr1[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &arr2[i][j]);
            }
        }
        int t;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                t = 0;
                for (int k = 0; k < n; ++k) {
                    t += arr1[i][k]*arr2[k][j];
                }
                arr3[i][j] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            printf("%d", arr3[i][0]);
            for (int j = 1; j < n; ++j) {
                printf(" %d", arr3[i][j]);
            }
            printf("\n");
        }
    }
}
void ADD(int a[100][100],int b[100][100],int c[100][100],
         int ax, int ay, int bx, int by, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j]=a[i+ax][j+ay]+b[i+bx][j+by];
        }
    }
}
void SUB(int a[100][100],int b[100][100],int c[100][100],
         int ax, int ay, int bx, int by, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j]=a[i+ax][j+ay]-b[i+bx][j+by];
        }
    }
}
void stra(int a[100][100],int b[100][100],int c[100][100],
          int ax, int ay, int bx, int by, int n){
    int S1[100][100];
    int S2[100][100];
    int S3[100][100];
    int S4[100][100];
    int S5[100][100];
    int S6[100][100];
    int S7[100][100];
    int S8[100][100];
    int S9[100][100];
    int S10[100][100];
    int P1[100][100];
    int P2[100][100];
    int P3[100][100];
    int P4[100][100];
    int P5[100][100];
    int P6[100][100];
    int P7[100][100];
    SUB(b,b,S1,0,n/2,n/2,n/2,n);
    ADD(a,a,S2,0,0,0,n/2,n);
    ADD(a,a,S3,n/2,0,n/2,n/2,n);
    SUB(b,b,S4,n/2,0,0,0,n);
    ADD(a,a,S5,0,0,n/2,n/2,n);
    ADD(b,b,S6,0,0,n/2,n/2,n);
    SUB(a,a,S7,0,n/2,n/2,n/2,n);
    ADD(b,b,S8,n/2,0,n/2,n/2,n);
    SUB(a,a,S9,0,0,n/2,0,n);
    ADD(b,b,S10,0,0,0,n/2,n);
}
void Strassen(){
    /*
     * 待解决。。。
     * */
    int N, n;
    int A[100][100];
    int B[100][100];
    int C[100][100];
    scanf("%d", &N);
    while (N--){
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &A[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &B[i][j]);
            }
        }
        stra(A,B,C,0,0,0,0,n);


        for (int i = 0; i < n; ++i) {
            printf("%d", C[i][0]);
            for (int j = 1; j < n; ++j) {
                printf(" %d", C[i][j]);
            }
            printf("\n");
        }
    }
}
int main() {
    Strassen();
    return 0;
}