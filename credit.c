#include <stdio.h>
#include <cs50.h>

int is_card (long n) {
    int count = 0;
    while (n != 0) {
        n = n/10;
        count++;
    }
    return count;
}

bool is_valid(long n, int digits) {
    int sum1 = 0, sum2 = 0, count = 0;
    long help = n;
    if (digits % 2 == 0) {
        while (n != 0) {
            n = n / 10;
            int x = n % 10;
            count++;
            if (((count % 2 == 0) && (digits % 2 == 1)) || ((count % 2 == 1) && (digits % 2 == 0))) {
                x *= 2; //every other digit multiply by 2
                if (x < 10) {
                    sum1 += x;
                } else {
                    sum1 += (x / 10 + x % 10);
                } // sum of products of every other digit multiply by 2
            } else {
                sum2 += x;
            }
        }
        sum2 += (help % 10);
    } else {
        while (n != 0) {
            int x = n % 10;
            n /= 10;
            count++;
            if (((count % 2 == 0) && (digits % 2 == 1)) || ((count % 2 == 1) && (digits % 2 == 0))) {
                x *= 2; //every other digit multiply by 2
                if (x < 10) {
                    sum1 += x;
                } else {
                    sum1 += (x / 10 + x % 10);
                } // sum of products of every other digit multiply by 2
            } else {
                sum2 += x;
            }
        }
    }

    if ((sum1 + sum2) % 10 == 0) {
        return true;
    } else {
        return false;
    }
}

int main(void) {

    long n;
    int digits;
    do {
        n = get_long("Number: \n");
        digits = is_card(n);
    } while (digits == 0);

    long first = n, second = n;
    while (first >= 10) {
        // first digit
        first /= 10;
    }
    while (second >= 100) {
        //second digit
        second /= 10;
    }
    second %= 10;

    if (is_valid(n,digits)) {
        if ((digits == 13 || digits == 16) && (first == 4)) {
            printf("VISA\n");
        } else if (digits == 15 && (first == 3 && (second == 4 || second == 7))) {
            printf("AMEX\n");
        } else if (digits == 16 && (first == 5 && (second >= 1 && second <= 5))) {
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }

}