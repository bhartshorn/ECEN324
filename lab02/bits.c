/***********************************************************************
* Program:
*    Lab Datalab
*    Brother Jones, ECEN 324
* Author:
*    Brandon Hartshorn
* Summary:
*    Lab 02: Avoiding conditionals
***********************************************************************/

/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *          Even though you may work as a team, all students should
 *          individually submit a solution.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>
//#include <stdio.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team =
{
   /* Team name: Replace with either:
      Your login ID (Linux Lab username) if working as a one person team
      or, ID1+ID2 where ID1 is the login ID of the first team member
      and ID2 is the login ID of the second team member.
       Example: joestudent+zmename */
   "bhartshorn+rbudd", 
   /* Student name 1: Replace with the name of first team member */
   "Brandon Hartshorn",
   /* Login ID 1: Replace with the login ID of first team member */
   "bhartshorn",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Name of the second team member */
   "Ryan Budd",
   /* Login ID 2: Login ID of the second team member */
   "rbudd"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
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

  Note that in order to make the dlc (data lab checker) happy you need
  to declare all variables at the first of the function.
      dlc happy with:                 dlc not happy with:
      ---------------                 -------------------
      int Funct( arg1, arg2) {          int Funct( arg1, arg2) {
         int varA = ~0;                    int varA = ~0;
         int varB = 1;                     varA = varA + 4;
         varA = varA + 4;                  int varB = 1;
          ...                               ...

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
     NOTE: You may create big constants using code.  
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
     NOTE: You may define additional functions while you are working to
           solve the problems, but the final submission should not have any.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return (~x) & (~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 2
 */
int bitXor(int x, int y) {
  return ~(~((~x) & y) & ~(x & (~y)));
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  return !!(x ^ y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  // We can't use *, but shift left 3 does the same thing
  // We want to target n *bytes*, which is n*8 bits
  int shift = n << 3;

  return (x >> shift) & 0xFF;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  // Shift the LSB all the way to the left, then count on arithmetic
  // right shift to carry it all the way right
  return (x << 31) >> 31;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // Clever trick? Just give me minus :P
  // I ditched this when I realised I could just shift back left by 1
  // int minus1 = ~((~n) + 1);

  // Creates a mask of 1's to blank out any ones created during
  // arithmetical shift
  int mask = ~(((1 << 31) >> n) << 1);
  int shifted = x >> n;
  return shifted & mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  // Create a mask with 1 in the MSB of each byte
  int mask = (1 << 24) + (1 << 16) + (1 << 8) + (1);
  int sum;
  // Count adds up the bits in each of the 4 bytes
  int count = x & mask;
  count = count + ((x >> 1) & mask);
  count = count + ((x >> 2) & mask);
  count = count + ((x >> 3) & mask);
  count = count + ((x >> 4) & mask);
  count = count + ((x >> 5) & mask);
  count = count + ((x >> 6) & mask);
  count = count + ((x >> 7) & mask);

  // Add together the values in each byte
  sum = (count & 0xFF) + ((count >> 8) & 0xFF) + ((count >> 16) & 0xFF) + ((count >> 24) & 0xFF);

  return sum;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  // int y = 0x80000000;
  // printf("\n%d", (y - x));
  // printf("\n%d\t%d[%x]", (1 >> y), y, y);
  // printf("\n%d\t%d[%x]\n", (1 >> x), x, x);

  // For some reason, I was failing the the test where x = 0x80000000.
  // I tested it with /my own/ 0x80000000, and it worked without the
  // work-around below. I found a reference to GCC only using the low
  // 5 bits for the shift operator, but that doesn't seem to be the case
  // from any of my other testing, EXCEPT when x = 0x80000000, where if
  // I shift it right by 27, placing the 1 in the 5th position, this
  // seems to work. Ultimately, it might be wise to shift through all
  // the bits this way. If x = 0, this will still work. The shift
  // operator is essentially a way to create a boolean operation since
  // I don't have access to any for this function.
  return (1 >> x) & (1 >> (x >> 27));
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
  // This is the only problem I had to look up an answer for.
  return x & ((~x) + 1);
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return ~0 & ~(1 << 31);
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  // int mask = (1 << 31);
  // int neg = (x & mask);
  return !(x & (1 << 31));
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  // TODO: There must be a better way...
  int flg_isneg = (1 << 31);
  int y_is_pos = !(y & flg_isneg);
  int x_is_pos = !(x & flg_isneg);
  int neg_y = (~y) + 1;
  int sub = x + neg_y;
  int sub_is_pos = !(sub & flg_isneg);
  int sub_is_zero = (y == x); //!(sub & ~0x0);
  // CASE 1: x is positive, y is negative
  int case1 = (x_is_pos & (!y_is_pos)); 
  // CASE 2: both positive or both negative, so x - y should be positive
  int case2 = ((x_is_pos & y_is_pos) | ((!x_is_pos) & (!y_is_pos))) & sub_is_pos & (!sub_is_zero);
  return case1 | case2;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /* Unsigned division by two is easy, since dividing using right shift
   * always rounds down (towards 0 in this case, as it should.) However,
   * we have negative numbers here, which should always be rounded /up/
   * (towards 0!)
   *
   * Bryant and O'hallaron reccomend this method of "biasing" the negative
   * number on page 106.
   */

  // flg_isneg is 0x80
  int flg_isneg = (1 << 31);

  // flg_full  is all 1's for negative x or all 0's for positive x
  int flg_full = ((x & flg_isneg) >> 31);

  // biased adds (1 << n) -1 only if x < 0
  int biased = (x + (flg_full & ((1 << n) + flg_full)));
  return biased >> n;
}

/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  // flg_isneg is TMin
  int flg_isneg = (1 << 31);

  // flg_full will contain either: all 1's for negative x
  //                               all 0's for positive x
  int flg_full = ((x & flg_isneg) >> 31);

  // if x is positive, x & ~flg_full will return the original number, while
  // the second statement will return all 0's. When OR'd, the original
  // number will be returned.
  //
  // if x is negative, x & ~flg_full will return all 0's, while
  // the second statement will return (~x) + 1, which equals -x. When OR'd,
  // -x will be returned.
  return (x & ~flg_full) | (((~x) + 1) & flg_full);
}

/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /* This problem is basically gleaned from Computer systems from Bryant and O'Hallaron
   * page 153. With two's-complement addition, we have two basic cases we need to check
   * for overflow. They are encapsulated in this table:
   *
   * |  x  |  y  |  Sum |
   * |-----|-----|------|
   * | Neg | Neg |  Pos |
   * | Pos | Pos |  Neg |
   *
   * If x is pos and y is neg or vice-versa, it is impossible to overflow. If neither
   * of the above overflow situations happen, we know it is safe to add x and y.
   *
   */

  int sum = x + y;
  // Store the positive state of the 3 variables as a 1 or 0
  int x_neg = (x >> 31) & 1;
  int y_neg = (y >> 31) & 1;
  int sum_neg = (sum >> 31) & 1;

  // Calculate whether one of the above overflow situations occured.
  int neg_over = x_neg & y_neg & !(sum_neg);
  int pos_over = !(x_neg) & !(y_neg) & sum_neg;

  // Return 1 if neither occured, 0 if one has
  return (!neg_over) & (!pos_over);
}
