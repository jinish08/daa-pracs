#include <bits/stdc++.h>
using namespace std;

int show_message(int number)
{
    int value;
    if (number == 1)
    {
        printf("Enter the first number:\n");
    }
    else
    {
        printf("Enter the second number:\n");
    }
    scanf("%d", &value);
    return value;
}

int base(int number)
{
    int n = 10;
    while (n < number)
    {
        n = n * 10;
    }
    return n / 10;
}

int max(int number, int b)
{
    int m = 1;
    while (m * b < number)
    {
        m++;
    }
    return m--;
}

int rest(int number, int b, int m)
{
    int rest = number - m * b;
    return rest;
}

int karatsuba(int n1, int n2)
{
    if (n1 < 10 || n2 < 10)
    {
        return n1 * n2;
    }
    int z0, z1, z2;
    int z2_1, z2_2;
    int b1, b2;
    int result;
    b1 = base(n1);
    b2 = base(n2);
    if (b1 > b2)
    {
        b1 = b2;
    }
    else
    {
        b2 = b1;
    }
    z2_1 = max(n1, b1);
    z2_2 = max(n2, b2);
    z2 = z2_1 * z2_2;
    z0 = rest(n1, b1, z2_1) * rest(n2, b2, z2_2);
    z1 = (z2_1 + rest(n1, b1, z2_1)) * (z2_2 + rest(n2, b2, z2_2));
    z1 = z1 - z0 - z2;
    result = z2 * b1 * b1 + z1 * b1 + z0;
    return result;
}

int main()
{
    int number1, number2, result;
    number1 = show_message(1);
    number2 = show_message(2);
    result = karatsuba(number1, number2);
    printf("Result of %d X %d is %d", number1, number2, result);
    return 0;
}