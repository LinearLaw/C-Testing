/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1

 1����~��&ʵ�����
	�����ͬ��0����ͬ��1��
 */
int bitXor(int x, int y) {
  return ~(x & y) & ~(~x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 2�����ض����Ƶ���С����
 */
int tmin(void) {
  return 1<<31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1

 3�����x�����Ķ�������������1�����򷵻�0
	���Ķ��������� 0x7fff ffff
 */
int isTmax(int x) {
  return !(~(x ^ (x + 1))) & !!(~x);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 4������ż��λΪ1���򷵻�1
	�Ƚ����е�����λ��Ϊ1�����ż��λȫΪ1����ʱx����ȫ1��ȫ1�򷵻�1��
 */
int allOddBits(int x) {
	int temp = 0x55 + (0x55 << 8) + (0x55 << 16) + (0x55 << 24);
  return !~(x | temp);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2

 5��ȡ����һ
 */
int negate(int x) {
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 6������һ��ASCII�ַ����жϸ��ַ��Ƿ���0-9�����֣��Ƿ���1�����Ƿ���0
	�ȼ�ȥһ��0x30����������֣���������0-9
	����������10��0-9���᷵��0��
		��γ���10���ֽ�� 8 + 2 ��8������3λ��2������1λ
	�õ��Ľ��ȡ�ǣ��õ�1��
 */
int isAsciiDigit(int x) {
	return (!((x + ~48 + 1) >> 31)) & !!((x + ~58 + 1) >> 31);

	// int temp = x + (~48 + 1);
	// return !((temp >> 3) + (temp >> 1));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 7��ʵ����Ԫ�����
	���xΪ0���򷵻�z;
	���x��Ϊ0���򷵻�y;
		��x������λȫ����Ϊ1����z��&���� ->���xΪ0������Ϊz�����xΪ��0������Ϊ0��
		0000 0000���κ������룬�����Ϊ0��
		1111 1111���κ������룬�����Ϊ������
 */
int conditional(int x, int y, int z) {
	x = !!x;
	x = ~x + 1;//����
	return (x&y) | (~x&z);
	
	//return ((!x << 31 >> 31) & y) | ((!!x << 31 >> 31) & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 8�����x <= y������1
	���x > y������0 

 */
int isLessOrEqual(int x, int y) {
	int negX = ~x + 1;//-x
	int addX = negX + y;//y-x
	int checkSign = addX >> 31 & 1; //y-x�ķ���
	int leftBit = 1 << 31;//���λΪ1��32λ�з�����
	int xLeft = x & leftBit;//x�ķ���
	int yLeft = y & leftBit;//y�ķ���
	int bitXor = xLeft ^ yLeft;//x��y������ͬ��־λ����ͬΪ0��ͬΪ1
	bitXor = (bitXor >> 31) & 1;//������ͬ��־λ��ʽ��Ϊ0��1
	return ((!bitXor)&(!checkSign)) | (bitXor&(xLeft >> 31));//����1�����������������ͬ��־λΪ0����ͬ��λ�� y-x �ķ���Ϊ0��y-x>=0�����Ϊ1��������ͬ��־λΪ1����ͬ��λ��x�ķ���λΪ1��x<0��

	
	// return ((x + (~y + 1)) >> 31) | (!(x^y));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 9��ʵ��!����
	�ؼ�����ʵ���ж�x==0
		0���ص㣬0000 0000 ȡ��+1�õ��Ļ���0000 0000������λû��
			�������0������1101 0011 ȡ��+1�õ�����0010 1101������λ���ˡ�
		���⻹��1000 0000 ȡ��+1�õ��Ļ���1000 0000��

	(^y & 1) ���x��0000 0000 ��y����0000 0000��(^y & 1)�õ�0000 0001
	
 */
int logicalNeg(int x) {
	int y = (x ^ (~x + 1)) >> 31;
  return (~y & 1) & (~(x >> 31) & 1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 10�����ر�ʾx�������Сλ��

 */
int howManyBits(int x) {
	int b16, b8, b4, b2, b1, b0;
	int mask = x >> 31;
	x = (mask & ~x) | (~mask & x); //���Ϊ���������ֲ��䣻���Ϊ��������λȡ��

	//step1:�жϸ�16Ϊ�Ƿ���1
	b16 = !!(x >> 16) << 4; //�����16Ϊ��1,��b16 = 16������Ϊ0
	x >>= b16; //�����16Ϊ��1,x����16λ������16λ,���µĵ�16λ�������ң����򱣳ֲ���

	//step2:�жϸ�8λ�Ƿ���1
	b8 = !!(x >> 8) << 3;
	x >>= b8;

	//step3:��4λ
	b4 = !!(x >> 4) << 2;
	x >>= b4;

	//step4:��2λ
	b2 = !!(x >> 2) << 1;
	x >>= b2;

	//step5:��1λ
	b1 = !!(x >> 1);
	x >>= b1;

	//step6:��1λ
	b0 = x;

	return b16 + b8 + b4 + b2 + b1 + b0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 11�����ظ������Ľ����С
	s:����λ  exp:����  frac: β��
		exp == 1111 1111  frac == 0 ->  �������
		exp == 1111 1111  frac != 0 ->  NaN
		exp!=0 && exp!=255  ->  ��񻯸�����
		exp == 0 ->  �ǹ�񻯸�����

 */
unsigned floatScale2(unsigned uf) {
	// �����ֵ
	int exp = (uf & 0x7f800000) >> 23;
	// ����λ
	int sign = (uf & (1 << 31));

	if (exp == 255) return uf; // 1��������NaN
	if (exp == 0) return uf << 1 | sign; // 2��0������С

	exp = exp + 1;
	if (exp == 255)
		return 0x7f800000 | sign; 
	return (exp << 23) | (uf & 0x807fffff);


}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4



 */
int floatFloat2Int(unsigned uf) {
	int sign = (uf >> 31) & 1;
	int exp = (uf >> 23) & 0xff;
	int frac = uf & 0x7fffff;

	int E = exp - 127;

	if (E < 0) //С��
	{
		return 0;
	}
	else if (E >= 31) // ����int��Χ
	{
		return 0x80000000u;
	}
	else
	{
		frac = frac | (1 << 23);  //����������1

		if (E < 23)     //��ȥ����С��
		{
			frac >>= (23 - E);
		}
		else        //����Ҫ��ȥС��
		{
			frac <<= (E - 23);
		}

		if (sign)
			return -frac;
		else
			return frac;
	}
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	if (x > 127) //too large, return +INF
	{
		return (0xFF << 23);
	}
	else if (x < -148) //too small, return 0
	{
		return 0;
	}
	else if (x >= -126) //norm������exp
	{
		int exp = x + 127;
		return (exp << 23);
	}
	else //denorm����frac��ĳһλΪ1
	{
		int t = 148 + x;
		return (1 << t);
	}
}
