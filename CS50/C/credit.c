#include <stdio.h>
#include <cs50.h>

string banks(long long n);
int main(void)
{
    long long number;
    do
    {
        number = get_long_long("Number: "); //read number
    }
    while (number < 0); //must be positive
    int sum1 = 0;
    int sum2 = 0;
    int n1, n2, sum;
    long long check1 = number;
    while (check1 > 0)
    {
        n1 = check1 % 10; //first igit from the right
        sum1 += n1; //add digit to sum 1
        check1 -= n1; // subtract the digit
        check1 /= 10; //go to second-to-last digit
        n2 = check1 % 10; //second digit from the right
        if ((n2 * 2) > 9) //if multiplying makes 2 digits
        {
            sum2 += (n2 * 2) % 10;
            sum2 ++; // = ((n2*2) - ((n2 * 2) % 10)) / 10; - longer method, but n2*2 cannot be more than 18
        }
        else
        {
            sum2 += (n2 * 2);
        }
        check1 -= n2;
        check1 /= 10;
    }

    string valid = "INVALID";
    sum = sum1 + sum2;
    if (sum % 10 == 0)
    {
        valid = banks(number);
    }
    printf("%s\n", valid);
}

string banks(long long n) // determines the creditor
{
    string bank = "INVALID";
    if (((340000000000000 < n) && (n < 350000000000000)) ||
        ((370000000000000 < n) && (n < 380000000000000)))
    {
        bank = "AMEX";
    }
    else if ((5100000000000000 < n) && (n < 5600000000000000))
    {
        bank = "MASTERCARD";
    }
    else if (((4000000000000 < n) && (n < 5000000000000)) ||
             ((4000000000000000 < n) && (n < 5000000000000000)))
    {
        bank = "VISA";
    }
    return bank;
}
