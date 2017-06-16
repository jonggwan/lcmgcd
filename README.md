# lcmgcd
Get LCM (Least Common Multiple) and GCD (Greatest Common Divisor) for arbitrary numbers using GMP (GNU Multiple Precision Arithmetic Library).
For arbitrary number arithmetic, it uses GMP (https://gmplib.org/).

Just compile with 'gcc -I/path/to/GMP/include -L/path/to/GMP/lib -lgmp lcmgcd.c -o lcmgcd'.

Sample output is:

    $ lcmgcd 14 28 36 40 56
    GCD is 2
    LCM is 2520
    $ lcmgcd 432893477 4819890128420984091578 41789471280742189471208471204714
    GCD is 1
    LCM is 43596844944725185707918084840983790569754701953318790207716042
