//Project 1
//Alec J. Taggart


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void conv_binary_to_signed_int(char *input);


long int x_to_the_n (int x,int n)
{
    int i; 
    int number = 1;

    for (i = 0; i < n; i++)
        number = number*x;

    return(number);
}

void conv_decimal_to_binary_to_signed_int(char *input){
	long int decimal = atoi(input);
	long int remainder,quotient;

    int binary[100];
    int i = 1;
    int j;
    quotient = decimal;
    while(quotient!=0){
         binary[i++]= quotient % 2;
         //printf("printing %d\n", binary[i]);
         quotient = quotient / 2;

    }
    // for(j = i-1; j > 0; j--){
    // 	printf("%d\n", binary[j]);
    // }
    //printf("BINARY = %d\n", binary);
    int x = ((i-1)%4);
    if(x != 0){
    	int add = 4-x;
	    // printf("LENGTH %d\n", i-1);
	    // printf("REMAINDER %d\n", (i-1)%4);
	    // printf("ADD THIS %d\n", x);
	    char final[i-1+x];
	    int p = x;
	    int t;
	    for(t = 0; t < x; t++){
	    	//printf("ZEROS LOL ");
	    	final[t] = '0';
	    }
	    for(j = i-1; j > 0; j--){
	    	if(binary[j] == 1)
	    		final[p] = '1';
	    	else
	    		final[p] = '0';
	    	p++;
	    }final[p] = '\0';
	    //printf("FINAL = %s\n", final);
	    conv_binary_to_signed_int(final);
	}else{

	    char final[i-1];
	    int p = 0;
	    
	    for(j = i-1; j > 0; j--){
	    	if(binary[j] == 1)
	    		final[p] = '1';
	    	else
	    		final[p] = '0';
	    	p++;
	    }final[p] = '\0';
	    //printf("FINAL = %s\n", final);
	    conv_binary_to_signed_int(final);
	}
    
}

int conv_hex_to_decimal(char *input){
	int i; 
	int inter = 0;
	int answer = 0;
	int power = 0;
	for(i = strlen(input)-1; i >= 0; i--){
		switch(input[i]) {
		   	case 'A' :
		   		//printf("Iterator %d\n", inter);
		   		power = x_to_the_n(16, inter);
		   		answer += (10*power);
	        	break;
		    case 'B' :
		    	power = x_to_the_n(16, inter);
		      	answer += (11*power);
		      	break;
		    case 'C' :
		    	power = x_to_the_n(16, inter);
		        answer += (12*power);
		        break;
		    case 'D' :
		    	power = x_to_the_n(16, inter);
		        answer += (13*power);
		        break;
		    case 'E' :
		    	power = x_to_the_n(16, inter);
		        answer += (14*power);
		        break;
		    case 'F' :
		    	power = x_to_the_n(16, inter);
		        answer += (15*power);
				break;
			case '0' :
				power = x_to_the_n(16, inter);
		        answer += (0*power);
				break;
			case '1' :
				power = x_to_the_n(16, inter);
		        answer += (1*power);
				break;
			case '2' :
				power = x_to_the_n(16, inter);
		        answer += (2*power);
				break;
			case '3' :
				power = x_to_the_n(16, inter);
		        answer += (3*power);
				break;
			case '4' :
				power = x_to_the_n(16, inter);
		        answer += (4*power);
				break;
			case '5' :
				power = x_to_the_n(16, inter);
		        answer += (5*power);
				break;
			case '6' :
				power = x_to_the_n(16, inter);
		        answer += (6*power);
				break;
			case '7' :
				power = x_to_the_n(16, inter);
		        answer += (7*power);
				break;
			case '8' :
				power = x_to_the_n(16, inter);
		        answer += (8*power);
				break;
			case '9' :
				power = x_to_the_n(16, inter);
		        answer += (9*power);
				break;
		}
		inter++;
	}
	return answer;
}

int conv_2comp_to_decimal(char *input){
	//printf("IN 2COMP%s\n", input);

	unsigned int n= 0;
	int c;
	// for (c = 1; input[c] != '\0'; c++) {
	for (c = 0; c < strlen(input); c++) {
		//printf("[%s]\n", input[c]);
    	n = (n * 10 + input[c]) - '0';
 	}


 	if(n == 2147483648){
		printf("1000 0000 0000 0000 0000 0000 0000 0000 (base 2) ");
		printf("0b10000000000000000000000000000000 (Base 2) ");
		printf("0x80000000 (Base 16)\n");
		return -1;
	}

 	n--;
 
	// char decimal[strlen(input)];
	// int i;
	// //printf("LENGTH INPUT%d\n", strlen(input));
	// for(i = 0; i < strlen(input); i++){
	// 	decimal[i] = input[i+1];
	// }decimal[i+1] = '\0';
	// long int decimalVal = atoi(decimal);

	// printf("AFTER A DECIMAL %ld\n", decimalVal);
	// decimalVal--;
	//printf("DECIMAL Value %d\n", decimalVal);
	long int remainder,quotient;

    int binary[100];
    int x = 1;
    int j;
    quotient = n;
    while(quotient!=0){
         binary[x++]= quotient % 2;
         quotient = quotient / 2;
    }
    int add;
    ((x-1)%4);
    if((x-1)%4 == 0){
    	add = 0;
    }else{
    	add = 4-((x-1)%4);
    }

    //printf("ADD THIS %d\n", add);
    //printf("ADD THIS %d\n", add);


 //    printf("PRINTING TO TEST BINARY BEFORE INVERSE\n");
 //    int u;
 //    for(u = x -1 ; u > 0 ; u--){
	// 	if(u%4 == 0){
	// 		printf("%d",binary[u]);
	// 	}else{
 //    		printf("%d",binary[u]);
	// 	}
	// }printf("\n");
 
	char inverse[x-1];
    int v;

    int p =0;
	for(j = (x-1) ; j > 0;j--){
		//printf("LOOP %d\n", p);
       	if(binary[j] == 1){
       		inverse[p] = '0';
       	}else{
       		inverse[p] = '1';
       	}
       	p++;
    }
    inverse[p] = '\0';
    //printf("INVERSE %s\n", inverse);
    
    int o;
    char final[strlen(inverse)+add];
    for(o = 0; o < add; o++)
    	final[o] = '1';
    int y;
    int l = 0;
    for(y = add; y < strlen(inverse)+add; y++){
    	final[y] = inverse[l];
    	l++;
    }final[l+add] = '\0';
  
    //printf("FINAL %s\n", final);

    int finallyDone = conv_binary_to_unsigned_int(final);
    //printf("PLEASE BE RIGHT %d\n", finallyDone);
    return finallyDone;
}

void conv_decimal_to_binary(char *input){
	//printf("IN BINARY %s\n", input);
	long int decimal = atoi(input);
	//printf("AFTER ATOI%d\n", decimal);
	long int remainder,quotient;
	//printf("TEST %d\n", decimal/2);

    int binary[100];
    int i = 1;
    int j;
    quotient = decimal;
    while(quotient!=0){
         binary[i++]= quotient % 2;
         //printf("QUOTIENT %d\n", quotient%2);
         quotient = quotient / 2;
    }
    //printf("BINARY = %d\n", binary);
    int x = 4-((i-1)%4);
    //printf(" NUM ZEROS %d\n", x);
    if((i-1)%4 == 0){
    	int u = j;
    	for(u = i -1 ; u > 0 ; u--){
    		if(u%4 == 0){
    			printf(" ");
    			printf("%d",binary[u]);
    		}else{
        		printf("%d",binary[u]);
    		}
    	}	
     	printf(" (Base 2) ");

    	printf("0b");
    	for(j = i -1 ;j> 0;j--)
        	printf("%d",binary[j]);
     	printf(" (Base 2) ");
     	
    }else{
    	int p;
    	for(p = 0; p < x; p++)
        	printf("0");

        int u = j;
    	for(u = i -1 ; u > 0 ; u--){
    		if(u%4 == 0){
    			printf(" ");
    			printf("%d",binary[u]);
    		}else{
        		printf("%d",binary[u]);
    		}
    	}	
     	printf(" (Base 2) ");


    	printf("0b");
    	int n;
    	for(n = 0; n < x; n++)
        	printf("0");
 		
 		for(j = i -1 ;j> 0;j--)
        	printf("%d",binary[j]);
     	printf(" (Base 2) ");

    }
}


char conv_decimal_to_hex(char *input){
	//printf("INPUT %s\n", input);
	char result[32];
	int counter = 1;
	char buffer[1];
	int quotient = atoi(input);
	
	int remainder;
	while(quotient != 0){
		remainder = quotient%16;
		quotient = quotient/16;
		if(remainder > 9){
			switch(remainder) {
		      case 10 :
		      	sprintf(buffer, "%c", 'A');
		        strcat(result, buffer);
		         break;
		      case 11 :
		      	 sprintf(buffer, "%c", 'B');
		        strcat(result, buffer);
		      	 break;
		      case 12 :
		        sprintf(buffer, "%c", 'C');
		        strcat(result, buffer);
		         break;
		      case 13 :
		        sprintf(buffer, "%c", 'D');
		        strcat(result, buffer);
		         break;
		      case 14 :
		        sprintf(buffer, "%c", 'E');
		        strcat(result, buffer);
		         break;
		      case 15 :
			    sprintf(buffer, "%c", 'F');
		        strcat(result, buffer);
			      break;
   			}
		}else{
			sprintf(buffer, "%d", remainder);
			strcat(result, buffer);
		}
		counter++;
	}
	//printf("RESULT BEFORE REVERSE %s\n", result);
	result[counter] = '\0';
	// printf("RESULT %s\n", result);
	// printf("LENGTH RESULT %d\n", strlen(result));
	
	int i;
	int j = 2;
	char output[strlen(result)+2];
	output[0] = '0';
	output[1] = 'x';
	for(i = strlen(result)-1; i >= 0; i--){
		output[j] = result[i];
		j++;
	}
	output[j] = '\0';

	printf("%s (Base 16) ", output);

}


void conv_binary_to_signed_int(char *input){
	//printf("ORIGINAL LENGTH %d\n", strlen(input));
	int decimalVal = conv_binary_to_unsigned_int(input);
	int i; 
	int len = strlen(input);
	char binary[len+1];
	for(i = 0; i < len; ++i){
		binary[i] = '1';
	}binary[i] = '\0';
	int andBit = conv_binary_to_unsigned_int(binary);
	int invert = ~decimalVal & andBit;
	invert++;
 	
	printf("-%d (Base 10) ", invert);
}

int conv_binary_to_unsigned_int(char *input){
	int i;
	int len = strlen(input);
	//Gets the power size 
	int powsize = strlen(input) - 1;
	int multiFactor = 1 << powsize;
	unsigned int bin_value;
	unsigned int uint_value = 0;

	for (i = 0; i < len; ++i){
		bin_value = (int) (input[i] - '0');
		uint_value += bin_value*multiFactor;
		multiFactor = multiFactor >> 1;
	}


	return uint_value;

	// FOR SOME REASON POW DOES NOT WORK WTF
	// int i;
	// int length = strlen(input) -1;
	// double value;
	// for (i = 0; i < strlen(input); ++i){
	// 	//printf("inside loop %d \n", i);
	// 	if(input[i] == '1'){
	// 		value += (int) pow(2.3, length);
	// 		length--;
	// 	}else{
	// 		length--;
	// 	}
	// }
	// printf("%d ", value);
	// printf("(Base 10)\n");

}




int isBinary(char *input){
	//Example of Input: 0b1111
	if (input[1] == 'b'){
		return 1;
	}
	return 0;
}

int isHex(char *input){
	//Example of Input: 0xF
	if (input[1] == 'x'){
		return 1;
	}
	return 0;

}

int is2Comp(char *input){
	//Example of Input: -111
	if (input[0] == '-'){
		return 1;
	}
	return 0;
}	

int isDecimal(char *input){
	//Example of Input: 713
	if (input[0] != '-' && input[1] != 'b' && input[1] != 'x'){
		return 1;
	}
	return 0;
}

void print_usage(){
	printf("./[name of program]  [arg to convert]\n");
	printf("arg types:\n-Decimal\n-2sComp\n-binary\n-Hexadecimal\n");
}

int if_zero_dec(char *input){
	int add = 4-(strlen(input)%4);
	int i = 0;
	int zero = 1;
	while(i != strlen(input)){
		//printf("HERE\n");
		if(input[i] != '0'){
			//printf("NON ZERO\n");
			zero = 0;
			break;
		}i++;

	}
	if(zero == 1){
		int x;
		printf("%s (Base 10) ", input );
		for(x = 0; x < add; x++)
			printf("0");
		printf("%s (Base 2) ", input);
		int p;
		printf("0b");
		for(p = 0; p < add; p++)
			printf("0");
		printf("%s (Base 2) ", input);
		int t;
		printf("0x");
		for(t = 0; t < add; t++)
			printf("0");
		printf("%s (Base 16) \n", input);


	}
	return zero;
}

int if_zero_hex(char *input){
	//("HELLO\n");
	int add;	
	if((strlen(input)%4) != 0){
		add = 4-strlen(input)%4;
	}else{
		add = 0;
	}

	int i = 0;
	int zero = 1;
	while(i != strlen(input)){
		//printf("inside\n");
		if(input[i] != '0'){
			zero = 0;
			break;
		}i++;
	}
	if(zero == 1){
		int x;
		printf("0x%s (Base 16) ", input );
		for(x = 0; x < add; x++)
			printf("0");
		printf("%s (Base 2) ", input);
		int p;
		printf("0b");
		for(p = 0; p < add; p++)
			printf("0");
		printf("%s (Base 2) ", input);
		int t;
		for(t = 0; t < add; t++)
			printf("0");
		printf("%s (Base 10) ", input);

		for(t = 0; t < add; t++)
			printf("0");
		printf("%s (Base 10) \n", input);
	}
	return zero;
}

int if_zero_binary(char *input){
	//("HELLO\n");
	int add;	
	if((strlen(input)%4) != 0){
		add = 4-strlen(input)%4;
	}else{
		add = 0;
	}

	int i = 0;
	int zero = 1;
	while(i != strlen(input)){
		//printf("inside\n");
		if(input[i] != '0'){
			zero = 0;
			break;
		}i++;
	}
	if(zero == 1){
		int x;
		printf("0b%s (Base 2) ", input );
		printf("0 (Base 10) ");
		printf("0 (Base 10) ");
		int p;
		
		int t;
		printf("0x");
		for(t = 0; t < add; t++)
			printf("0");
		printf("%s (Base 10) ", input);

	}
	return zero;
}

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Incorrect Number of Args\n");
		print_usage();
		exit(-1);
	}
	char *numstr = argv[1];
	//CHECK FOR ZERO CASE
	int zero = if_zero_dec(numstr);
	if(zero == 1)
		exit(-1);

	////Print out input :3
	// int i;
	// printf("INPUT = ");
	// for (i = 0; i < strlen(numstr); ++i)
	// {
	// 	printf("%c", numstr[i]);
	// }
	// printf("\n");
	
	//CHECK FOR TYPE
	if(1 == isBinary(numstr)){
		//printf("\n");
		if(strlen(numstr) > 34){
			printf("Invalid: Input larger than 32 Bit\n");
			exit(-1);
		}

		int i;
		char value[strlen(numstr)-2];
		for(i = 0; i < strlen(numstr)-2; ++i){
			value[i] = numstr[i+2];
		}
		value[i++] = '\0';
		int zero = if_zero_binary(value);
		if(zero == 1)
			exit(-1);


		printf("%s (Base 2) ",numstr);
		printf("%d (Base 10) ", conv_binary_to_unsigned_int(value));
		conv_binary_to_signed_int(value);
		
		int decimal = conv_binary_to_unsigned_int(value);	
		char buffer[32];
		snprintf(buffer, 32, "%d", decimal);
		buffer[strlen(buffer)] = '\0';
	
		conv_decimal_to_hex(buffer);
		printf("\n");
	
	}
	if(1 == isDecimal(numstr)){
		char max[10] = "2147483647";
		if(strlen(numstr) > 10){
			printf("Invalid: Input larger than 32 Bit\n");
			exit(-1);
		}
		if(strlen(numstr) == 10){
			int i;
			for (i = 0; i < 10; ++i){
				if(numstr[i] > max[i]){
					printf("Invalid: Input larger than 32 Bit\n");
					exit(-1);
				}
			}

		}

		printf("%s (Base 10) ", numstr);
		//decimal to non op binary

		conv_decimal_to_binary(numstr);
		
		conv_decimal_to_hex(numstr);
		
		printf("\n");
	
	}
	if (1 == is2Comp(numstr)){
		//printf("\n");

		char max[11] = "-2147483648";
		printf("PLEASE WORK %d\n", atoi(max));
		if(strlen(numstr) > 11){
			printf("Invalid: Input larger than 32 Bit\n");
			exit(-1);
		}
		if(strlen(numstr) == 11){
			int i;
			for (i = 1; i <= 10; ++i){
				//printf("INPUT %d MAX COMP %d\n", (int) numstr[i], (int) max[i]);
				if(numstr[i] > max[i]){
					printf("Invalid: Input larger than 32 Bit\n");
					exit(-1);
				}
			}

		}
		//printf("INPUT %s\n", numstr);

		printf("%s (Base 10) ", numstr);
		int i;
		char value[strlen(numstr)-1];
		for(i = 0; i < strlen(numstr)-1; ++i){
			value[i] = numstr[i+1];
		}
		value[i++] = '\0';
		//printf("HERE PLEASE%s\n", value);
		int decimal = conv_2comp_to_decimal(value);
		if(decimal == -1){
			
			return;
		}
		//printf("AFTER DECIMAL%d\n", decimal);
		char string[32];
		sprintf(string, "%d", decimal);

		conv_decimal_to_binary(string);
		conv_decimal_to_hex(string);
		printf("\n");
		//FINISHED THIS 
		
	}
	if(1 == isHex(numstr)){
	
		printf("%s (Base 16) ", numstr);
		if(strlen(numstr) > 10){
			printf("Invalid: Input larger than 32 Bit\n");
			exit(-1);
		}

		int i;
		char value[strlen(numstr)-2];
		for(i = 0; i < strlen(numstr)-2; ++i){
			value[i] = numstr[i+2];
		}
		value[i++] = '\0';

		int zero = if_zero_hex(value);
		if(zero == 1)
			exit(-1);

		
		int decimal = conv_hex_to_decimal(value);
		char string[32];
		sprintf(string, "%d", decimal);
		conv_decimal_to_binary(string);
		printf("%d (Base 10) ", decimal);
		conv_decimal_to_binary_to_signed_int(string);
		printf("\n");

	}

	return 0;
}

//0, 1, 2, -1, -2, 
