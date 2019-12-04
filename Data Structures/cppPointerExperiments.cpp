#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int bs(int a , int b) {
    if (a < b) {
        return b - a;
    } else return a - b;
}

int add(int a , int b) {
    return a + b;
}

void sayHello(char* name) {
    printf("Hello %s\n", name);
}

bool compareASC(int a, int b) {
    return a > b;
}

bool compareDESC(int a, int b) {
    return a < b;
}

bool compareABS_ASC(int a, int b) {
    return abs(a) > abs(b);
}

void swwwap(int* a, int* b) {
    int c = *b;
    *b = *a;
    *a = c;
}

void bubbleSort(int* a, int n,bool (*compare)(int, int)) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (compare(a[i], a[j])) {
                swwwap(&a[i], &a[j]);
            }
        }
    }
}

int compareForQSort(const void* a, const void* b) {
    int A_VAL = *((int*)a);
    int B_VAL = *((int*)b);

    return A_VAL - B_VAL;
}

using namespace std;
int main () {
    int v1 = 10;
    printf("v1 = %d\n", v1);
    int *p1 = &v1;
    *p1 = 11;
    printf("v1 = %d\n", v1);
    int **p2 = &p1;
    **p2 = *p1 + 1;
    printf("v1 = %d\n", v1);
    int ***p3 = &p2;
    ***p3 = **p2 + 1;
    printf("v1 = %d\n", v1);

    printf("p1 is a pointer to v1; &p1 = %d and &v1 = %d\n", &p1, &v1);

    int i = 1027;
    int* pi = &i;
    char* pc;
    pc = (char*)pi;

    /// 1027 in binary is:
    /// 00000000 00000000 00000100 00000011

    printf("sizeof int = %d, sizeof char = %d\n", sizeof(int), sizeof(char));
    printf("address of pi = %d , value in address that pi points to = %d\n", pi, *pi);
    printf("address of pc = %d , value in address that pc points to = %d\n", pc, *pc);
    printf("address of pc+1 = %d, value in address that pc+1 points to = %d\n", pc+1, *(pc+1));

    int x = 10;
    int* px;

    px = &x;

    printf("address of px = %d\n", &px);
    printf("value that px stores = %d\n", px);
    printf("*px = %d\n", *px);

    *px = *px + 1;
    printf("(*px = *px + 1) = %d\n", *px);
    printf("x = %i\n", x);

    int a[] = {1,2,3,4,5};

    printf("a[2] = %d\n", a[2]);
    printf("*(a + 2) = %d\n", *(a+2));
    printf("*a = %d\n", *a);
    printf("&a = %d\n" , &a);
    printf("&a[0] = %d\n", &a[0]);
    printf("a = %d\n", a);

    int* p = a;

    for (int i = 0; i < 5; i++) {
        printf ("%d ", *p);
        p++;
    }
    printf("\n");


    int b[2][3] = {{2,4,6}, {1,3,5}};

    int *pb = &b[0][0];

    printf("%d, %d\n",pb, b);

    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {
            printf("%d %d\n", pb, *( *(b + i) + j));
            pb++;
        }
    }

    printf("%d %d\n", *b + 2 , *( *b + 2) );

    int C[4][2][3] = { {{1,2,3}, {4,5,6}} , {{7,8,9}, {10,11,12}}, {{13,14,15}, {16,17,18}}, {{19,20,21}, {22,23,24}} };

    int (*PC)[2][3] = C;

    printf("Addresses allocated for C:\n");
    for (int i=0; i<24; i++) {
        printf("%d ", *(*C)+i);
    }

    // C[1][1][0]
    printf("\nC[1][1][0] (v, &) = %d %d\n", *(*( *(C+1) + 1 )), *( *(C+1) + 1 ));

    // C[3][1][2]
    printf("C[3][1][2] (v, &) = %d %d\n", *(*(*(C+3) + 1) + 2) , *(*(C+3)+1)+2 );

    // malloc, calloc, realloc, free
    int N;
    printf("Enter the size of the array: ");
    scanf("%d",&N);

    int *PA1 = (int*) malloc(N * sizeof(int));

    printf("default int values allocated by malloc are:\n");
    for (int i=0; i<N; i++) {
        printf("%d ", PA1[i]);
    }
    printf("\nLets enter some values there, now values are:\n");
    for (int i=0; i<N; i++) {
        *(PA1+i) = i+1;
    }

    for (int i=0; i<N; i++) {
        printf("%d ", *(PA1+i));
    }

    printf("\nLet's free the memory allocated for PA1, now values are:\n");
    free(PA1);

    for (int i=0; i<N; i++) {
        printf("%d ", *(PA1+i));
    }
    printf("\n---------------------------------\n");
    printf("Creating a new array PA2 with calloc\n");
    int* PA2 = (int*)calloc(N, sizeof(int));

    printf("default int values allocated by calloc are:\n");
    for (int i=0; i<N; i++) {
        printf("%d ", PA2[i]);
    }
    printf("\nLets enter some values there, now values are:\n");
    for (int i=0; i<N; i++) {
        *(PA2+i) = i+1;
    }

    for (int i=0; i<N; i++) {
        printf("%d ", *(PA2+i));
    }

    printf("\nLets reallocate 2*N memory units starting from PA2 for new array PA3\n");
    int* PA3 = (int*) realloc(PA2, 2*N*(sizeof(int)));
    printf("Address of PA2 = %d and address of PA3 = %d\n", PA2, PA3);
    printf("%d values at PA3 block now are:\n", 2*N);
    for (int i=0; i<2*N; i++) {
        printf("%d ", *(PA3+i));
    }
    printf("\nLet's fill them with values");
    for (int i=0; i<2*N; i++) {
        PA3[i] = i+1;
    }

    printf("\nValues at PA3 block now are:\n", 2*N);
    for (int i=0; i<2*N; i++) {
        printf("%d ", *(PA3+i));
    }
    printf("\nNow let's reduce the size of array to N/2 using realloc, values are (Actual size is %d):\n", N/2);
    PA3 = (int*)realloc(PA3, (N/2)*sizeof(int));
    for (int i=0; i<2*N; i++) {
        printf("%d ", *(PA3+i));
    }
    printf("\nCalling realloc(PA3, 0) where 0 is size, is same as using free(PA3), means deallocation memory block of PA3, Let's try\n");
    PA3 = (int*)realloc(PA3, 0);
    printf("Here are values in PA3 now: (the memory block is deallocated, so it means that it's free for usage, you must set PA3 to null now)\n");
    /*
    for (int i=0; i<N; i++) {
        printf("%d ", *(PA3+i));
    }
    */

    printf("\nCalling realloc with first argument as NULL is same as calling malloc, here is example:\nPA4 = realloc(NULL, %d*sizeof(int)), values are:\n",N);
    int* PA4 = (int*) realloc(NULL, N*sizeof(int));
        for (int i=0; i<N; i++) {
        printf("%d ", *(PA4+i));
    }
    free(PA4);
    printf("\nMemory freed\n");

    void (*helloCb)(char*);
    int (*addCb)(int,int);

    printf("Calling callback (pointer to a function) of a hello function for CodeSchool\n");
    char codeSchool[] = "CodeSchool";
    helloCb = sayHello;
    helloCb(codeSchool);
    printf("Calling callback of add function for 5 and 5 (*addCb)(5,5)\n");

    addCb = &add; ///OR JUST add -- also returns address of a function
    printf("add res = %d\n", (*addCb)(5,5));

    printf("Calling callback of add function for 5 and 5 different w/o dereferencing addCb(5,5)\n");
    printf("addTwo res = %d\n", addCb(5,5));

    int ARR[] = {5, -6 , 1 , 7 ,2 ,3 , -10, 7, 5};

    printf("We have an array: ");
    N = 9;
    for (int i=0; i < N; i++) {
        printf("%d ", ARR[i]);
    }
    printf("\nLets bubble sort it using callbacks in ASC\n result is:");
    bubbleSort(ARR, N, compareASC);
    for (int i=0; i < N; i++) {
        printf("%d ", ARR[i]);
    }

    printf("\nLets bubble sort it using callbacks in DESC\n result is:");
    bubbleSort(ARR, N, compareDESC);
    for (int i=0; i < N; i++) {
        printf("%d ", ARR[i]);
    }

    printf("\nLets bubble sort it using callbacks in ABS_ASC\n result is:");
    bubbleSort(ARR, N, compareABS_ASC);
    for (int i=0; i < N; i++) {
        printf("%d ", ARR[i]);
    }
    printf("\nSorting with qsort of stdlib.h using callback for a compare function\nValues are: ");
    qsort(ARR,N,sizeof(int), compareForQSort);
    for (int i=0; i < N; i++) {
        printf("%d ", ARR[i]);
    }
    return 0;
}
