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
		
	printf("Valor bits: %d \n",CHAR_BIT);	
	
	printf("\nValor em binário: ");	
	print_binary(0xff);
	printf("Tem %d sequência a 1.\n",charLeadingOnes( 0xff ));

	printf("\nValor em binário: ");	
	print_binary(0x0f);
	printf("Tem %d sequência a 1.\n",charLeadingOnes( 0x0f ));

	printf("\nValor em binário: ");	
	print_binary(0xf0);
	printf("Tem %d sequência a 1.\n",charLeadingOnes( 0xf0 ));
	
	printf("\nValor em binário: ");	
	print_binary(0xaa);
	printf("Tem %d sequência a 1.\n",charLeadingOnes( 0xaa ));
	
	printf("\nValor em binário: ");	
	print_binary(0xc0);
	printf("Tem %d sequência a 1.\n",charLeadingOnes( 0xc0 ));
	
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
