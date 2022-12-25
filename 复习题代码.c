//英寸对应的厘米数 
#include <stdio.h>
int main(){
	float inch;
	float inch_1; 
	printf("情输入英寸值：\n");
	scanf("%f",&inch);
	inch_1=2.54*inch;
	printf("%.1f英寸等于%.3f厘米",inch,inch_1);
	return 0;
} 
