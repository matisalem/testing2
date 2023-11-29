/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * Matias Salem - 800753703
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */

#endif
/* Copyright (C) 1991-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
    // deMorgan's Law
    int mandar = ~x&~y;
    return mandar;
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {

    // x represents the binary of 1000 0000
    int x = 0x80;

    // move the 1 in x 24 positions, so that becomes 1000 0000 0000 0000 0000 0000 0000 0000
    int y = x << 24;

    // return the negative of y. The 1 in the beginning will change to be a 0 (Meaning y will be positive)
    // the following 0 will become a 1
    return ~y;
}
//2
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {

    // shift n by 3. Each shift to the left by 1 == multiplying by 2, so w = n * 8
    int w = n<<3;

    // shift x by w, looking for the desired byte
    x = x>>w;

    // this isolates the least significant byte
    x = x&0xFF;
    return x;
}
/*
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */

// PREGUNTAR
int allEvenBits(int x) {

    // pares is the 32 bit representation of very odd = 0 & every even = 1
    int mask = 0x55; // Allowed constant
    int pares = mask | mask << 8 | mask << 16 | mask << 24;
    // compare each bit of two numbers. Gives 1 if both bits are 1, and 0 if not
    int w = x & pares;

    // compare each bit of two numbers. Gives 1 if the bits are different, and 0 if not
    // if everything is the same in w and pares, each bit should be 0, so invert with ! to return 1
    return !(w ^ pares);
}
//3
/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int ezThreeFourths(int x) {

    // shifting left by 1 bit == * 2, and then doing + x is same as x * 3
    int multiplicacion = (x << 1) + x;

    // determines sign of x
    int signo = multiplicacion >> 31;

    // if positive, bias == 0, else bias == 3
    int bias = signo & 3;

    // add the bias to the multiplication
    int calculo = multiplicacion + bias;

    // shifting right by 2 == divide by 4
    int total = calculo >> 2;

    return total;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {

    // of course, begin by shifting
    int shift = x >> n;

    // now we have to build something to correct the leftover bits?
    // mask begin as -1 (all bits == 1), then shift left by (32 - n), leaving zeros on the right and retains n ones on the left.
  //  int something = -1 << (32 - n);

    // invert so leftmost n bits are zeros and the rightmost (32 - n) bits are ones (opposite as we did above)
  //  something = ~something;

    // final calculation, clears the leftmost n bits and keeps rest of them.
 //   int final = shift & something;

    int mask = ~(((1 << 31) >> n) << 1);


    return shift & mask;
}
//4
/*
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4
 */
int greatestBitPos(int x) {

    // propagate the most significant 1 bit of x across to the right, ensuring that all bits to the right of this bit are set to 1
    int a = x | (x >> 1);
    int b = a | (a >> 2);
    int c = b | (b >> 4);
    int d = c | (c >> 8);
    int e = d | (d >> 16);

    // create a mask that has 0 at the position of the most significant 1 bit of x and 1s elsewhere
    // it turns off all bits that were set during the propagation, except the most significant one.
    int elon = (e^(e>>1));

    // mask with only the most significant bit set, this is for edge cases!
    int  mask = (1<<31);

    // first, combine both masks to ensure the sign bit is set right,
    // and then take out the most significant bit from e. Return the result
    return (elon | mask) & e;
}
/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) {

    // shift x 31 bits to the right, isolating the sign bit
    int signoX = (x >> 31) & 1;

    // negate x using ~ and + 1
    int notX = ~x + 1;

    // isolate the sign bit of the negation of x
    int signoNotX = (notX >> 31) & 1;

    // combine sing bit of x and its negative. If is non-zero, should return 1,
    // if is zero, returns 0 because the sign bit of 0 and ~0 is both 0
    return signoX | signoNotX;
}
//float
/*
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) {

    // find where most significant bit is
    // variables I'll use later, but somehow compiler threw an error if created later
    int exponent = 31;
    int roundBit = 0;
    int stickyBit = 0;
    unsigned fraction = 0;
    int mask = 1 << 31;

    unsigned sign = 0;

    // if x == 0, return 0
    if (x == 0) return 0;

    // if x is negative
    if (x < 0) {
        sign = 0x80000000; // this is sign bit for negatives
        if (x == mask) {
            x = mask; // keep x as the minimum integer
        } else {
            x = -x; // turn x to its positive
        }
    }

    //  Find the position of the most significant bit (remember exponent at first == 31)
    while (!(x & mask)) {

        // normalize the fraction by aligning the msb of x to the leftmost position.
        x <<= 1;

        // getting exponent right
        exponent--;
    }

    // get the exponent, and use 127 as bias becuase it is used to avoid having to store negative numbers
    // and in single-precision floating-point numbers, bias is 127
    exponent += 127;

    // control paranormal numbers
    if (exponent < 127) {
        // adjust
        exponent = 0;
        fraction = x >> 8; // paranormal numbers use a different representation
    } else {
        // normalize the fraction by removing the most significant bit and shifting
        fraction = (x & (~mask)) >> 8;
    }

    // get the bit immediately to the right of the fraction
    roundBit = (x >> 7) & 1;

    // remaining bits.
    stickyBit = x & 0x7F;


    // rounding logic to handle the bits that are right of the target precision
    if ((roundBit && stickyBit) || (roundBit && (fraction & 1))) {
        fraction++;

        // if adding 1 to fraction caused an overflow
        if (fraction >> 23) {
         // manage overflow in fraction
            fraction = 0;
            exponent++;
        }
    }

    // construct the final floating-point representation
    return sign | (exponent << 23) | (fraction & 0x007FFFFF);
}
/*
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned input) {
    // Extracting the sign bit from the input
    int signBit = input & 0x80000000;
    int i;

    // We need to multiply by 64, equivalent to 6 consecutive doublings (2^6)
    for (i = 0; i < 6; i++) {
        // Extracting the exponent field from the input
        int exponentField = input & 0x7F800000;

        // Checking if the exponent is zero (denormalized number)
        int isDenormalized = (exponentField == 0);

        if (isDenormalized) {
            // If denormalized, shift left by 1 (double the value)
            input = signBit | (input << 1);
        } else if (exponentField != 0x7F800000) {
            // If not denormalized or infinity/NaN, increment the exponent
            input += 0x800000;

            // Re-extracting the exponent to check for overflow
            exponentField = input & 0x7F800000;

            // If the result is infinity (overflow), clear the fraction field
            if (exponentField == 0x7F800000) {
                input &= 0xFF800000;
            }
        }
    }

    // Return the final scaled value
    return input;
}







/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {

    // grab exponents, by shifting right 23 bits and keeping only the last 8 bits (not the first one :))
    unsigned exponent = (uf >> 23) & 0xFF;

    // extract the fraction part by keeping only the last 23 bits
    unsigned fraction = uf & 0x7FFFFF;

    // check for NaN, by looking if exponent is all 1s (0xFF) and fraction is not xero
    if (exponent == 0xFF && fraction != 0) return uf;

    // Toggle the sign bit:
    // - XOR with 0x80000000 flips the most significant bit
    return uf ^ 0x80000000;
}
