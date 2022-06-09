#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[2][2], b[2][2], c[2][2], i, j, m1, m2, m3, m4, m5, m6, m7;
    printf("MATRIX A\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter the value:");
            scanf("%d", &a[i][j]);
        }
    }

    printf("MATRIX B\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter the value:");
            scanf("%d", &b[i][j]);
        }
    }

    m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    m2 = (a[1][0] + a[1][1]) * b[0][0];
    m3 = a[0][0] * (b[0][1] + b[1][1]);
    m4 = a[1][1] * (b[1][0] - b[0][0]);
    m5 = (a[0][1] + a[0][0]) * b[1][1];
    m6 = (a[1][0] - a[0][0]) * (b[0][1] + b[0][0]);
    m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = m1 + m4 - m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;

    printf("Entered Matrix A:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    printf("Entered Matrix B:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    printf("Product Matrix using Strassen's Multiplication Algorithm:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// begin 
// 	If n = threshold then compute
// 		C = a * b is a conventional matrix.
// 	Else
// 		Partition a into four sub matrices  a11, a12, a21, a22.
// 		Partition b into four sub matrices b11, b12, b21, b22.
// 		Strassen ( n/2, a11 + a22, b11 + b22, d1)
// 		Strassen ( n/2, a21 + a22, b11, d2)
// 		Strassen ( n/2, a11, b12 – b22, d3)
// 		Strassen ( n/2, a22, b21 – b11, d4)
// 		Strassen ( n/2, a11 + a12, b22, d5)
// 		Strassen (n/2, a21 – a11, b11 + b22, d6)
// 		Strassen (n/2, a12 – a22, b21 + b22, d7)

// 		C = d1+d4-d5+d7     d3+d5
// 		d2+d4           d1+d3-d2-d6  
		
// 	end if
	
// 	return (C)
// end.