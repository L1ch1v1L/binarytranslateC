#include <stdio.h>
#include <stdlib.h>

void d_to_b();
void calc_d_to_b(int *number);
void b_to_g();
int power(int base, int exp);

void main()
{
while(1){
    int choose;
    printf("\t\tMENU\n");
    printf("\t\t1) Decimal to Binary;\n");
    printf("\t\t2) Binary to Decimal;\n");
    printf("\t\t");
    printf("> ");
    scanf("%d",&choose);
    if (choose == 1){
        d_to_b();
        break;
    }
    else if (choose == 2){
    	b_to_g();
    	break;
    }

}

}
void d_to_b(){
    int number;
    printf("Write a decimal number:");
    scanf("%d",&number);
    calc_d_to_b(&number);
}
void calc_d_to_b(int *number){
    int new_number,module_number,minus_number,end;
    int* bin_number = (int *)malloc(16*sizeof(int));
    for (int i = 0;i <= 64;++i)
    {
    if (*number == 0) {end = i; break;}
    new_number = *number / 2;
    minus_number = new_number * 2;;
    module_number = *number - minus_number;
    *number = new_number;
    bin_number[i] = module_number;
    }
    int* rev_number = (int *)malloc(end*sizeof(int));
    for(int i = 0, d = end-1;i <= end;++i,--d)
    {
        rev_number[i] = bin_number[d];
    }
    printf("binary number is:");
    for(int q = 0;q < end; ++q)
    {
        printf("%d",rev_number[q]);
    }
    printf("\n");
}

void b_to_g(){
	int sum = 0;
	int multiply_number;
	int new_number;
	int count;
	printf("how many numbers in number:\n");
	scanf("%d",&count);
	int* number = (int *) malloc(count*sizeof(int));
	printf("Write a binary number:\n");
	for(int i = 0;i<=count-1;++i)
	{
		scanf("%d",&number[i]);
	}
	for (int i = count-1,d = 0;i >= 0;--i, ++d)
	{
		multiply_number = power(2,i);
		new_number = number[d] * multiply_number; 
		sum += new_number;
	}
	printf("decimal number is: %d\n",sum);
}

int power(int base, int exp) {
    int i = 0,result = 1;
    if (exp == 0) return 1;
	do {
		result *= base;
		++i;
	}
	while(i<exp);
    return result;
 }
