#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int num;
    scanf("%d", &num);
    int abs_num = abs(num);
    int precise = 1e-8;
    int actual_precise = 0, guess=0;
    int left = 0, right = abs_num;
    do{
        guess = left + right >> 1;
        int guess_3 = pow(guess,3);
        if (guess_3 > abs_num) right = guess;
        else left = guess;
    }while(abs(pow(guess,3)-abs_num)>precise);
    printf("%d",guess*abs_num/num);
}