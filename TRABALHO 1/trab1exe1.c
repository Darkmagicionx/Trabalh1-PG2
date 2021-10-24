#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MASK (1 << (CHAR_BIT - 1))
#define INT_BYTE_SIZE (sizeof(int))
#define INT_BIT_SIZE (INT_BYTE_SIZE * 2)

int charLeadingOnes( char value );
void print_binary(int num);
bool get_bit(char val, int position);


int main(){
	
	char val;
	
	printf("Valor bits: %d \n",CHAR_BIT);	
	
	printf("Insere valor: ");
	val = getchar();
	print_binary(val);
	

	int countSeqBit = charLeadingOnes( val );

	printf("\nTem %d sequência a 1.\n",countSeqBit);
	
	return 0;
}

int charLeadingOnes( char value ){

	int i = 0;
	
	while (get_bit(value , (CHAR_BIT - i)-1)){
		i++;
	}
	return i;
}



bool get_bit(char val, int position)
{
	char mask = 1 << position;
	return mask & val;
}


void print_binary(int num)
{

	for(unsigned int mask = 1 << (INT_BIT_SIZE - 1) ; mask ; mask >>= 1)
	{
		if(mask & num)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	
	printf("\n");
}	
