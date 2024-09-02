#include <stdio.h>
int main(){
	int n,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int data[n],result[n],oddnum=0,evennum=n-1;
	for(i=0;i<n;i++){
		scanf("%d",(data+i));
	}
	
	for(i=0;i<n;i++){
		if(data[i]%2 != 0){
			result[oddnum] = data[i];
			oddnum++;
		}
		else{
			result[evennum] = data[i];
			evennum--;
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d ",*(result+i));
	}
	return 0;
}

