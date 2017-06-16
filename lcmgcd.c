#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "gmp.h"

int check_digit(char *arg)
{
        size_t i, len;

        len=strlen((const char*)arg);
        for(i = 0; i < len; i++)
        {
                if ( !isdigit((int)arg[i]) )    return 0;
        }
        return 1;
}

int main(int argc, char *argv[])
{
        int i;
        long n1,n2;
        char *gcdval=NULL, *lcmval=NULL;
        mpz_t gcd, lcm, num1, num2;

        if (argc <= 2)
        {
                printf("Usage : %s [list of positive integers with space]\n", argv[0]);
                return 1;
        }
        for(i=1; i < argc; i++)
        {
                if ( !check_digit(argv[i]) )
                {
                        printf("Usage : %s [list of positive integers with space]\n", argv[0]);
                        return 1;
                }
                if (argv[i][0]=='0')
                {
                        printf("Usage : %s [list of positive integers with space]\n", argv[0]);
                        return 1;
                }
        }

        mpz_init(gcd);
        mpz_init(lcm);
        mpz_init(num1);
        mpz_init(num2);

        if(0 != mpz_set_str(num1,argv[1],10)) {
                printf("Argument %s conversion error\n",argv[1]);
                mpz_clear(gcd);
                mpz_clear(lcm);
                mpz_clear(num1);
                mpz_clear(num2);
                return 1;
        }
        if(0 != mpz_set_str(num2,argv[2],10)) {
                printf("Argument %s conversion error\n",argv[2]);
                mpz_clear(gcd);
                mpz_clear(lcm);
                mpz_clear(num1);
                mpz_clear(num2);
                return 1;
        }

        mpz_lcm(lcm,num1,num2);
        mpz_gcd(gcd,num1,num2);

        for(i=3; i < argc; i++)
        {
                if(0 != mpz_set_str(num1,argv[i],10)) {
                        printf("Argument %s conversion error\n",argv[i]);
                        mpz_clear(gcd);
                        mpz_clear(lcm);
                        mpz_clear(num1);
                        mpz_clear(num2);
                        return 1;
                }
                mpz_lcm(lcm, lcm, num1);
                mpz_gcd(gcd, gcd, num1);
        }

        lcmval = mpz_get_str(NULL,10,lcm);
        gcdval = mpz_get_str(NULL,10,gcd);

        mpz_clear(gcd);
        mpz_clear(lcm);
        mpz_clear(num1);
        mpz_clear(num2);

        printf("GCD is %s\n",gcdval);
        printf("LCM is %s\n",lcmval);

        return 0;
}
