#include "calc.h"





int valueOf(char current){
	if(isalpha(current)) current = tolower(current);
	switch(current){
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case '0': return 0;
	case 'a': return 10;
	case 'b': return 11;
	case 'c': return 12;
	case 'd': return 13;
	case 'e': return 14;
	case 'f': return 15;
	default: return -1;
	}
}
int iszero(struct node *number){
	if (number->next == NULL){
		if (number->num == 0) return 1;
	}
	else{
		if (number->num == 0 &&
				number->next->num == 0) return 1;
	}
	return 0;
}
struct node* changeSign(struct node *number){
	struct node *temp = number;
	if(number->num == 0){
		number = number->next;
		if (number != NULL) number->prev = NULL;
		temp->next = NULL;
		free(temp);
		return number;
	}
	else{
		struct node* temp = (struct node *)malloc(sizeof(struct node));
		temp->num = 0;
		temp->next = number;
		number->prev = temp;
		return temp;
	}
}
struct node* convert(char *numberString){
	unsigned int total = 0;
	int arsize;
	int charsize;
	unsigned int prevtot = 0;
	struct node *result = NULL;
	struct node *head = NULL;
	char base;
	int curr;
	unsigned int length;
	if(numberString[0] == '-' || numberString[0] == '0'){
		base = numberString[1];
		curr = 2;
		arsize = sizeof(numberString);
		charsize = sizeof(numberString[0]);
	}
	else {
		base = numberString[0];
		curr = 1;
		arsize = sizeof(numberString);
		charsize = sizeof(numberString[0]);
	}
	base = tolower(base);
	length = strlen(numberString);
	switch(base){
	case 'b':
		for(; curr < length; curr++){
			prevtot = total;
			total = (total * 2) + (unsigned int)valueOf(numberString[curr]);
			if(prevtot > total){
				result = (struct node *)malloc(sizeof(struct node));
				result->num = prevtot;
				result->next = head;
				if (head != NULL) head->prev = result;
				head = result;
				total = (unsigned int)valueOf(numberString[curr]);
			}
		}
		result = (struct node *)malloc(sizeof(struct node));
		result->num = total;
		result->next = head;
		if (head != NULL) head->prev = result;
		head = result;
		break;

	case 'o':
		for(; curr < length; curr++){
			prevtot = total;
			total = (total * 8) + (unsigned int)valueOf(numberString[curr]);
			if(prevtot > total){
				result = (struct node *)malloc(sizeof(struct node));
				result->num = prevtot;
				result->next = head;
				if (head != NULL) head->prev = result;
				head = result;
				total = (unsigned int)valueOf(numberString[curr]);
			}
		}
		result = (struct node *)malloc(sizeof(struct node));
		result->num = total;
		result->next = head;
		if (head != NULL) head->prev = result;
		head = result;
		break;

	case 'd':
		for(; curr < length; curr++){
			total = (total * 10) + (unsigned int)valueOf(numberString[curr]);
		}
		result = (struct node *)malloc(sizeof(struct node));
		result->num = total;
		result->next = NULL;
		result->prev = NULL;
		head = result;
		total = (unsigned int)valueOf(numberString[curr]);

		break;

	case 'x':
		for(; curr < length; curr++){
			prevtot = total;
			total = (total * 16) + (unsigned int)valueOf(numberString[curr]);
			if(prevtot > total){
				result = (struct node *)malloc(sizeof(struct node));
				result->num = prevtot;
				result->next = head;
				if (head != NULL) head->prev = result;
				head = result;
				total = (unsigned int)valueOf(numberString[curr]);
			}
		}
		result = (struct node *)malloc(sizeof(struct node));
		result->num = total;
		result->next = head;
		if (head != NULL) head->prev = result;
		head = result;
		break;
	}
	if(numberString[0] == '-'){
		result = (struct node *)malloc(sizeof(struct node));
		result->num = 0;
		result->next = head;
		if (head != NULL) head->prev = result;
		head = result;
	}
	return head;
}
struct node *add(struct node *number1, struct node *number2){
	struct node *result = NULL;
	struct node *head = NULL;
	struct node *tail = NULL;
	struct node *num1ptr = number1;
	struct node *num2ptr = number2;
	unsigned int leftover = 0;
	unsigned int carry = 0;
	unsigned int total = 0;
	if (num1ptr->num == 0 && num2ptr->num == 0){
		return result = changeSign(add(changeSign(num1ptr), changeSign(num2ptr)));
	}
	else if(num1ptr->num == 0 && num2ptr->num != 0){
		return result = subtract(num2ptr, changeSign(num1ptr));
	}
	else if(num1ptr->num != 0 && num2ptr->num == 0){
		return result = subtract(num1ptr, changeSign(num2ptr));
	}
	while(num1ptr != NULL && num2ptr != NULL){
		total = num1ptr->num + num2ptr->num;
		if(total < num1ptr->num || total < num2ptr->num){ /* overflow case */
			if(num1ptr->num > num2ptr->num)	leftover = num1ptr->num - (UINT_MAX - num2ptr->num);
			else leftover = num2ptr->num - (UINT_MAX - num1ptr->num);
			result = (struct node *)malloc(sizeof(struct node));
			result->num = leftover + carry;
			carry = 1; /* carry 1 over to the next significant node */
			if (tail == NULL) head = result;
			else tail->next = result;
			tail = result;
			num1ptr = num1ptr->next;
			num2ptr = num2ptr->next;
			continue;
		}
		else{
			result = (struct node *)malloc(sizeof(struct node));
			result->num = total + carry;
			carry = 0;
			if (tail == NULL) head = result;
			else tail->next = result;
			tail = result;
			num1ptr = num1ptr->next;
			num2ptr = num2ptr->next;
			continue;
		}
	}



	return result;
}

struct node *subtract(struct node *number1, struct node *number2){
	struct node *result = NULL;
	struct node *head = NULL;
	struct node *tail = NULL;
	int total = 0;
	int negative = 0;
	struct node *num1ptr = number1;
	struct node *num2ptr = number2;
	if (num1ptr->num == 0 && num2ptr->num == 0){
		return result = add(number1, changeSign(number2));
	}
	else if (num1ptr->num != 0 && num2ptr->num == 0){
		return result = add(number1, changeSign(number2));
	}
	else if (num1ptr->num == 0 && num2ptr->num != 0){
		return changeSign(result = add(changeSign(number1), number2));
	}
	while(num1ptr != NULL && num2ptr != NULL){

		if (num1ptr->num > num2ptr->num){
			total = num1ptr->num - num2ptr->num;
			negative = 0;
		}
		else{
			total = num2ptr->num - num1ptr->num;
			negative = 1;
		}

		result = (struct node *)malloc(sizeof(struct node));
		result->num = total;
		if(tail == NULL) head = result;
		else tail->next = result;
		tail = result;
		num1ptr = num1ptr->next;
		num2ptr = num2ptr->next;
		continue;
	}

	if(negative == 1) result = changeSign(result);
	return result;
}

struct node *quicksum(struct node *number1, struct node *number2){
	struct node *result;
	if(iszero(number1) && iszero(number2)) return NULL;
	if(iszero(number1)) return number2;
	if(iszero(number2)) return number1;
	if (number1->num == 0 && number2->num == 0){
		return result = changeSign(quicksum(changeSign(number1), changeSign(number2)));
	}
	else if(number1->num == 0 && number2->num != 0){
		return result = quicksub(number2, changeSign(number1));
	}
	else if(number1->num != 0 && number2->num == 0){
		return result = quicksub(number1, changeSign(number2));
	}
	result = (struct node *)malloc(sizeof(struct node));
	result->num = number1->num + number2->num;
	result->next = NULL;
	result->prev = NULL;
	return result;
}

struct node *quicksub(struct node *number1, struct node *number2){
	struct node *result;
	return result;
}

void printhelp(void){
	printf("Usage Interface:\n");
	printf("calc <op> <number1> <number2> <output base>\n");
	printf("The first argument, <op>, is either the, +, for addition, or -, for subtraction\n");
	printf("The next two arguments <number1> and <number2> are integers of arbitrary size.\n");
	printf("Each of the numbers should be in this form: -?(b|o|d|x)dn, dn-1, ...., d1, d0 \n");
	printf("which can be interpreted as: a number can optionally start with a '-' sign, followed by a base indicator,\n");
	printf("where b means the number is a binary number, o means octal,  means decimal, and x means hexadecimal. \n");
	printf("dn, ..., d0 are the digits of a number.\n");
	printf("The final argument, <output base>, gives the base that the resulting number should be printed out in.\n");
	printf("Like the base indicator for the input numbers, this argument can be one of four strings:\n");
	printf("b, for binary\n");
	printf("o, for octal\n");
	printf("d, for decimal\n");
	printf("h, for hexadecimal\n");
	printf("The program should output the answer in the same form as the input numbers.\n");
}
void printBinary(struct node *target){
	int i = 0;
	int num = target->num;
	int remainder;
	int out[32];
	memset(out, 0, 32*sizeof(int));
	if (target->next == NULL){
		for(i = 0; i < 32; i++){
			remainder = num % 2;
			out[i] = remainder;
			num = num / 2;
			if(num == 0) break;
		}
		if(i == 32) i--;
		for(; i >= 0; i--){
			if(out[i] == 1) printf("1");
			else printf("0");
		}
		return;
	}
	for(i = 0; i < 32; i++){
		remainder = num % 2;
		out[i] = remainder;
		num = num / 2;
	}
	i--;
	for(; i >= 0; i--){
		if(out[i] == 1) printf("1");
		else printf("0");
	}
}
void printOct(struct node *target){
	int i = 0;
	int num = target->num;
	int remainder;
	int out[32];
	memset(out, 0, 32*sizeof(int));
	if (target->next == NULL){
		for(i = 0; i < 32; i++){
			remainder = num % 8;
			out[i] = remainder;
			num = num / 8;
			if (num == 0) break;
		}
		if (i == 32) i--;
		for(; i >= 0; i--){
			switch(out[i]){
			case 1:	printf("1"); break;
			case 2: printf("2"); break;
			case 3: printf("3"); break;
			case 4: printf("4"); break;
			case 5: printf("5"); break;
			case 6: printf("6"); break;
			case 7: printf("7"); break;
			case 0: printf("0"); break;
			}
		}
		return;
	}
	for(i = 0; i < 32; i++){
		remainder = num % 8;
		out[i] = remainder;
		num = num / 8;
	}
	i--;
	for(; i >= 0; i--){
		switch(out[i]){
		case 1:	printf("1"); break;
		case 2: printf("2"); break;
		case 3: printf("3"); break;
		case 4: printf("4"); break;
		case 5: printf("5"); break;
		case 6: printf("6"); break;
		case 7: printf("7"); break;
		case 0: printf("0"); break;
		}
	}
}
void printHex(struct node *target){
	int i = 0;
	int num = target->num;
	int remainder;
	int out[32];
	memset(out, 0, 32*sizeof(int));
	if (target->next == NULL){
		for(i = 0; i < 32; i++){
			remainder = num % 16;
			out[i] = remainder;
			num = num / 16;
			if (num == 0) break;
		}
		if (i == 32) i--;
		for(; i >= 0; i--){
			switch(out[i]){
			case 1:	printf("1"); break;
			case 2: printf("2"); break;
			case 3: printf("3"); break;
			case 4: printf("4"); break;
			case 5: printf("5"); break;
			case 6: printf("6"); break;
			case 7: printf("7"); break;
			case 8: printf("8"); break;
			case 9: printf("9"); break;
			case 0: printf("0"); break;
			case 10: printf("a"); break;
			case 11: printf("b"); break;
			case 12: printf("c"); break;
			case 13: printf("d"); break;
			case 14: printf("e"); break;
			case 15: printf("f"); break;
			}
		}
		return;
	}
	for(i = 0; i < 32; i++){
		remainder = num % 16;
		out[i] = remainder;
		num = num / 16;
	}
	i--;
	for(; i >= 0; i--){
		switch(out[i]){
		case 1:	printf("1"); break;
		case 2: printf("2"); break;
		case 3: printf("3"); break;
		case 4: printf("4"); break;
		case 5: printf("5"); break;
		case 6: printf("6"); break;
		case 7: printf("7"); break;
		case 8: printf("8"); break;
		case 9: printf("9"); break;
		case 0: printf("0"); break;
		case 10: printf("a"); break;
		case 11: printf("b"); break;
		case 12: printf("c"); break;
		case 13: printf("d"); break;
		case 14: printf("e"); break;
		case 15: printf("f"); break;
		}
	}
}
void printDecimal(struct node *target){
	int i = 0;
	int out[32];
	int remainder;
	int num;
	memset(out, 0, 32*sizeof(int));
	num = target->num;
	for (i = 0; i < 32; i++){
		remainder = num % 10;
		out[i] = remainder;
		num = num / 10;
		if(num == 0) break;
	}

}
void print(struct node *number, char base){
	struct node *curr = number;
	struct node *prev = NULL;
	if(iszero(number)) {
		printf("0");
		return;
	}
	switch(base){
	case 'b':
		printf("b");
		/* Mod each node, starting at the most significant bit, then keep going until you hit the least significant, and return*/
		while(curr != NULL){
			prev = curr;
			curr = curr->next;
		}
		/* prev is now at the last node */
		while (prev != NULL){
			printBinary(prev);
			prev = prev->prev;
		}
		break;
	case 'o':
		printf("o");
		/* Mod each node, starting at the most significant bit, then keep going until you hit the least significant, and return*/
		while(curr != NULL){
			prev = curr;
			curr = curr->next;
		}
		/* prev is now at the last node */
		while (prev != NULL){
			printOct(prev);
			prev = prev->prev;
		}
		break;
	case 'x':
		printf("x");
		/* Mod each node, starting at the most significant bit, then keep going until you hit the least significant, and return*/
		while(curr != NULL){
			prev = curr;
			curr = curr->next;
		}
		/* prev is now at the last node */
		while (prev != NULL){
			printHex(prev);
			prev = prev->prev;
		}
		break;
	case 'd':
		printf("d");
		/* Mod each node, starting at the most significant bit, then keep going until you hit the least significant, and return*/
		while(curr != NULL){
			prev = curr;
			curr = curr->next;
		}
		/* prev is now at the last node */
		while (prev != NULL){
			printDecimal(prev);
			prev = prev->prev;
		}
		break;
	default:
		printf("Bad Output Base");
	}
	return;
}
int inputCheck(char **argv){
	char base1;
	char base2;
	char outbase;
	if (argv[1][0] != '+' && argv[1][0] != '-')	return -1;
	if (argv[2][0] == '-'){
		base1 = argv[2][1];
		if(base1 != 'b' && base1 != 'd' && base1 != 'x' && base1 != 'o'){
			fprintf(stderr, "ERROR: first input base is bad");
			return -1;
		}
	}
	else{
		base1 = argv[2][0];
		if(base1 != 'b' && base1 != 'd' && base1 != 'x' && base1 != 'o'){
			fprintf(stderr, "ERROR: first input base is bad");
			return -1;
		}
	}
	if (argv[3][0] == '-'){
		base2 = argv[3][1];
		if(base2 != 'b' && base2 != 'd' && base2 != 'x' && base2 != 'o'){
			fprintf(stderr, "ERROR: second input base is bad");
			return -1;
		}
	}
	else{
		base2 = argv[3][0];
		if(base2 != 'b' && base2 != 'd' && base2 != 'x' && base2 != 'o'){
			fprintf(stderr, "ERROR: second input base is bad");
			return -1;
		}
	}
	outbase = argv[4][0];
	if(outbase != 'b' && outbase != 'd' && outbase != 'x' && outbase != 'o'){
		fprintf(stderr, "ERROR: output base is bad");
		return -1;
	}
	return 1;


}
void printint(int number){
	int remainder = 0;
	int out[32];
	int i = -1;
	int sign;
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
int main(int argc, char **argv){
	char operator;
	int incheck;
	struct node *number1;
	struct node *number2;
	struct node *result;
	char outputBase;
	if(argc == 1){
		fprintf(stderr, "ERROR: Too few inputs\n");
		return 0;
	}
	incheck = inputCheck(argv);
	if (incheck == -1) return 0;
	outputBase = argv[4][0];
	if (strcmp(argv[1], "-h") == 0){
		printhelp();
		return 0;
	}
	operator = argv[1][0];
	number1 = convert(argv[2]);
	number2 = convert(argv[3]);
	if(outputBase == 'd'){
		if(operator == '+') result = quicksum(number1, number2);
		else if (operator == '-') result = quicksub(number1, number2);
		else{
			fprintf(stderr, "ERROR: Bad operator!\n");
			return 0;
		}
		printf("d");
		printint(number1->num+number2->num);
		return 0;
	}
	if (operator == '+') result = add(number1, number2);
	else if (operator == '-') result = subtract(number1, number2);
	else{
		fprintf(stderr, "ERROR: Bad operator!\n");
		return 0;
	}
	print(result, outputBase);
	printf("\n");
	return 0;
}
