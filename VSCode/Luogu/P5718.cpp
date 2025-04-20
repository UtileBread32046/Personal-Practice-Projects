#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n>100||n<0){
		return 0;
	}
	int min,number;
	int i=0;
	scanf("%d",&min);
	int validInput=1;
	if(min<0 || min>1000){
		return 0;
	}else{
		for(i=1;i<=n;i++){
			scanf("%d",&number);
			if(number>=0&&number<=1000){
				if(number<min){
					min=number;
					validInput=1;
		        }
			}else{
				validInput=0;
			}
		}
	}
	if(validInput==1){
	    printf("%d",min);
	}
	return 1;
}