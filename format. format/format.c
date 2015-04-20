#include "format.h"
void printhelp(void){
	printf("Usage Interface: format <input bit sequence> <type> \nThe first argument, <input bit sequence>, is a sequence of 32 bits. "
			"This sequence of bits represents the binary values stored in 4 contiguous bytes in memory. \nThe leftmost bits are stored in the byte with the smallest address \nwhile the right most bits"
			"are stored in the byte with the largest address. \nThe second argument, <type>, gives the type that you should use to interpret the input bit sequence, \nand can either be int (integer) or float.\n"
			"The formats for the input bit sequence is as follows: \n int: the format is two's complement; \n float: the format is IEEE 74 single precision;\n \nThe program will print out the decimal representation"
			"of the input bit sequence, assuming a big endian byte ordering. \nFloating point numbers will be printed in scientific notation.\n");
}
int inputCheck(char **input){
	if(strlen(input[1]) != 32){
		fprintf(stderr, "ERROR: Second argument is not 32 bit");
		return -1;
	}
	return 1;
}
unsigned long int power(int num1, int num2){
	int i = 1;
	unsigned long int total = 1;
	for(i = 0; i < num2; i++){
		total = total*num1;
	}
	return total;
}
double dpower(double num1, double num2){
	double total = 1.0;
	int i;
	if (num2 < 0){
		for(i = 0; i > num2; i--){
			total = total / num1;
		}
		return total;
	}
	for(i = 0; i < num2; i++){
		total = total*num1;
	}
	return total;

}
double convert(char *binaryString){
	double i = 0.0;
	int count = 31;
	double result = 0.0;
	for(; i < 32; i++){
		if(binaryString[count] == '1'){
			result = result + power(2, i);
		}
		count--;

	}
	return result;
}
void print(int number){
	int remainder;
	int i;
	int out[32];
	for(i = 0; i < 32; i++){
		remainder = number % 10;
		number = number / 10;
		out[i] = remainder;
		if (number == 0) break;
	}
	if(i == 32) i--;
	for(; i >= 0; i--){
		switch(out[i]){
		case 1: printf("1");
		break;
		case 2: printf("2");
		break;
		case 3: printf("3");
		break;
		case 4: printf("4");
		break;
		case 5: printf("5");
		break;
		case 6: printf("6");
		break;
		case 7: printf("7");
		break;
		case 8: printf("8");
		break;
		case 9: printf("9");
		break;
		case 0: printf("0");
		break;
		}
	}



}
void printint(int number){
	int remainder = 0;
	int out[3];
	int i = -1;
	int sign;
	if(number == 0) printf("0");
	if(number < 0){
		sign = 1;
		number *= -1;
	}
	while(number != 0){
		i++;
		remainder = number % 10;
		number = number / 10;
		switch(remainder){
		case 1: out[i] = 1;
			break;
		case 2: out[i] = 2;
			break;
		case 3: out[i] = 3;
			break;
		case 4: out[i] = 4;
			break;
		case 5: out[i] = 5;
			break;
		case 6: out[i] = 6;
			break;
		case 7: out[i] = 7;
			break;
		case 8: out[i] = 8;
			break;
		case 9: out[i] = 9;
			break;
		case 0: out[i] = 0;
			break;
		}
	}
	if(sign == 1) printf("-");
	for(; i >=0; i--){
		switch(out[i]){
		case 1: printf("1"); break;
		case 2: printf("2"); break;
		case 3: printf("3"); break;
		case 4: printf("4"); break;
		case 5: printf("5"); break;
		case 6: printf("6"); break;
		case 7: printf("7"); break;
		case 8: printf("8"); break;
		case 9: printf("9"); break;
		case 0: printf("0"); break;
		}
	}
}
void printfloat(double decimal, int exp){
	int i;
	if(decimal == 0){
		printf("0.0e0");
		return;
	}
	if(decimal < 2){
		printf("1");
		decimal = decimal - 1;
		decimal = decimal * 10;
	}
	else if(decimal < 3){
		printf("2");
		decimal = decimal - 2;
		decimal = decimal * 10;
	}
	else if(decimal < 4){
		printf("3");
		decimal = decimal - 3;
		decimal = decimal * 10;
	}
	else if(decimal < 5){
		printf("4");
		decimal = decimal - 4;
		decimal = decimal * 10;
	}
	else if(decimal < 6){
		printf("5");
		decimal = decimal - 5;
		decimal = decimal * 10;
	}
	else if(decimal < 7){
		printf("6");
		decimal = decimal - 6;
		decimal = decimal * 10;
	}
	else if(decimal < 8){
		printf("7");
		decimal = decimal - 7;
		decimal = decimal * 10;
	}
	else if(decimal < 9){
		printf("8");
		decimal = decimal - 8;
		decimal = decimal * 10;
	}
	else{
		printf("9");
		decimal = decimal - 9;
		decimal = decimal * 10;
	}
	printf(".");
	for(i = 0; i < 20; i++){
		if(decimal < 1){
			printf("0");
			decimal = decimal * 10;
		}
		else if(decimal < 2){
			printf("1");
			decimal = decimal - 1;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}
		else if(decimal < 3){
			printf("2");
			decimal = decimal - 2;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}
		else if(decimal < 4){
			printf("3");
			decimal = decimal - 3;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}
		else if(decimal < 5){
			printf("4");
			decimal = decimal - 4;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}
		else if(decimal < 6){
			printf("5");
			decimal = decimal - 5;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}
		else if(decimal < 7){
			printf("6");
			decimal = decimal - 6;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}
		else if(decimal < 8){
			printf("7");
			decimal = decimal - 7;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}
		else if(decimal < 9){
			printf("8");
			decimal = decimal - 8;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}
		else{
			printf("9");
			decimal = decimal - 9;
			decimal = decimal * 10;
			if(decimal == 0) break;
		}

	}
	printf("e");
	printint(exp);
}

void invertbinary(int *arr){
	int i;
	for(i = 0; i < 32; i++){
		if(arr[i] > 0) arr[i] = 0;
		else arr[i] = 1;
	}
}
int complement(unsigned long int binary){
	int i;
	int arr[32];
	int count = 0;
	int remainder;
	for(i = 31; i >= 0; i--){
		remainder = binary % 2;
		binary = binary / 2;
		arr[i] = remainder;
	}
	binary = 0;
	invertbinary(arr);
	for(i = 31; i >= 0; i--){
		binary = binary + arr[i]*power(2, count);
		count++;
	}
	binary = binary + 1;
	return binary;

}
double getmantissa(char *input){
	int i = 9;
	double mantissa = 0;
	for(; i < 32; i++){
		if(input[i] == '1')
			mantissa = mantissa + dpower(2, (0-(i-8)));
	}
	return mantissa;
}
double getdenmantissa(char *input){
	int i = 31;
	double mantissa = 0;
	for(; i >= 9; i--){
		if(input[i] == '1')
			mantissa = mantissa + dpower(2, 31-i);
	}
	return mantissa;
}
int getexp(char *input){
	int exp = 0;
	int i;
	for(i = 8; i > 0; i--){
		if(input[i] == '1'){
			exp = exp + dpower(2.0, 8-i);
		}
	}
	return exp;
}
int getsign(char *input){
	int sign;
	if (input[0] == '1') sign = 1;
	else sign = 0;
	return sign;
}
double truncate(double decimal){
	int temp;
	decimal = decimal * 100000000000000000000.0;
	temp = (int)decimal;
	decimal = temp;
	decimal = decimal / 100000000000000000000.0;
	return decimal;
}
int main(int argc, char **argv){
	int i = 0;
	unsigned long int binary = 0;
	char *type;
	double mantissa = 0.0;
	double decimal = 0.0;
	int exponent = 0;
	int expbinary = 0;
	int tenexp = 0;
	int sign = -1;
	unsigned long int max = power(2, 31);
	if(argc == 1){
		fprintf(stderr, "ERROR: Too few inputs");
		return 0;
	}
	if (strcmp(argv[1], "-h") == 0){
		printhelp();
		return 0;
	}
	if(inputCheck(argv) == -1) return 0;
	type = argv[2];
	binary = convert(argv[1]);
	if(strcmp(type, "int") == 0){
		if((binary & max) == 0){
			print(binary);
			return 0;
		}
		binary = complement(binary);
		printf("-");
		print(binary);
		return 0;
	}
	else{
		expbinary = getexp(argv[1]);
		sign = getsign(argv[1]);
		if(expbinary == 255){
			mantissa = getmantissa(argv[1]);
			if(mantissa == 0){
				if(sign > 0) printf("ninf");
				else printf("pinf");
				return 0;
			}
		}
		if(sign > 0) printf("-");
		if(expbinary == 0){
			mantissa = getdenmantissa(argv[1]);
			exponent = 1 - 127;
			decimal = mantissa;
			while (decimal > 10){
				decimal = decimal / 10.0;
				tenexp++;
			}
			for(i = 0; i > exponent; i--){
				decimal = decimal / 2;
				while (decimal < 1 && decimal != 0){
					decimal = decimal * 10;
					tenexp--;
				}
			}
			printfloat(decimal, tenexp);
			return 0;

		}
		mantissa = getmantissa(argv[1]);
		exponent = expbinary - 127;
		decimal = mantissa + 1;
		if(exponent < 0){
			for(i = 0; i > exponent; i--){
				decimal = decimal / 2;
				while (decimal < 1){
					decimal = decimal * 10;
					tenexp--;
				}
			}
		}
		else if(exponent > 0){
			for(i = 0; i < exponent; i++){
				decimal = decimal * 2;
				while (decimal >= 10){
					decimal = decimal / 10;
					tenexp++;
					decimal = truncate(decimal);
				}
			}
		}
		else {
			while (decimal >= 10){
				decimal = decimal / 10;
				tenexp++;
				decimal = truncate(decimal);
			}
			while (decimal < 0){
				decimal = decimal * 10;
				tenexp--;
			}
		}
		printfloat(decimal, tenexp);
	}
	return 0;
}

















