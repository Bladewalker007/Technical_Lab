#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n=1,a[12][5],posx,posy=11,prof=0;


int choice(int x){
	if(x!=5||x<5){
		return x;
	}
	else{
		n=1;
		return n;
	}
}


void make_board(){
	srand(time(NULL));
	for(int i=0;i<12;i++){
		for(int j=0;j<5;j++){
			a[i][j]=((rand()%4)+1);
			n++;
		}
	}	
}


void show_board(){
	for(int i=0;i<5;i++){
		printf("\t%d",i);
	}
	printf("\n");
	for(int i=0;i<5;i++){
		printf("\t_");
	}
	printf("\n\n");
	for(int i=0;i<12;i++){
		printf("%d-\t",i);
		for(int j=0;j<5;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n\n");
	}	
}


int maxi(int m=0,int n=0,int o=0){
	if(m>n&&m>o){
		return(m);
	}
	else if(n>o){
		return(n);
	}
	else{
		return(o);
	}
}

void result(){
	printf("The Maximum Profit Gain by this game is %d",prof);
}


int descision(int posx){
	if(posy<0){
		result();
		return 1;
	}
	int p1=0,n1=0,n2=0,n3=0,p2=0,p3=0,max;
	//printf("Initial : \nn1=%d\nn2=%d\nn3=%d\n",n1,n2,n3);
	if(posx==0){
		p2 = posx;
		n2 = a[posy][p2];
		p3 = posx+1;
		n3 = a[posy][p3];
	}
	else if(posx==4){
		p1=posx-1;
		n1=a[posy][p1];
		p2=posx;
		n2=a[posy][p2];
	}
	else{
		p1=posx-1;
		n1=a[posy][p1];
		p2=posx;
		n2=a[posy][p2];
		p3=posx+1;
		n3=a[posy][p3];
	}
	//printf("After : \nn1=%d\nn2=%d\nn3=%d\np1=%d\np2=%d\np3=%d\n",n1,n2,n3,p1,p2,p3);
	max= maxi(n1,n2,n3);
	printf("\nCurrent max : %d\n",max);
	if(max==n1){
		posx=p1;
	}
	else if(max==n2){
		posx=p2;
	}
	else{
		posx=p3;
	}
	prof=prof+max;
	//printf("Current posx is : %d\n",posx);
	//printf("Current Profit is : %d\n\n\n",prof);
	printf("\nCurrent Position is a[%d][%d]\n",posy,posx);
	posy--;
	return(descision(posx));
}


int main(void){
	int k;
	make_board();
	show_board();
	posx=2;
	printf("\nStarting Position is a[%d][%d]\n",posy,posx);
	prof=prof+a[posy][posx];
	posy=posy-1;
	k = descision(posx);
}
