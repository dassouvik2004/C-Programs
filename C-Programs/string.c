#include <stdio.h>
#include <string.h>
int main(){
	int size;
	char str1[] = "abdeksgh";
	char str2[] = "k";
	
	size_t pos = strcspn(str1,str2);
	printf("The first occurance of any character from %s to %s is at position: %zu\n",str1,str2,pos);
	printf("The character of str1[]: %c",str1[7]);
	return 0;
}
