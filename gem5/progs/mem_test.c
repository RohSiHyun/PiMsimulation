#include <stdio.h>

int main(){
	int a[65535];
	for(int i = 0; i < 65535; i ++){
		a[i] = 0;
	}
	printf("value stored in a before ++: %d", a[0]);
	for(int i = 0; i < 65535; i ++){
		a[i]++;
	}	
	printf("value stored in a after ++: %d", a[0]);



	return 0;
}
