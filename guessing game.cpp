//  MEMORY LEAKS in C and C++ .

// betting game.
//pointers lecture 16 
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int bet_logic(int*);
int shuffle(char*);

int main(){
	printf("_________________BETTING GAME________________\n\nThe cards are K, Q and J for king, queen and jack respectively\n\n");
	int money = 200;
	
	bet_logic(&money);
	
	getchar();
    return 0;
}

int bet_logic(int* money){
	*(money) -= 20;
	
//	char arr[] = {'K','Q','J'};      // if we dynamically allocate this without deleting the dynamic alloation ,it would result in a memory leak.
    char* arr;
	arr = (char*)calloc(3,sizeof(char));
    arr[0] = 'K'; arr[1] = 'Q'; arr[2] = 'J';
    printf("__________________________________________\n");
	printf("shuffling...............\n");
	shuffle(arr);                             // shuffling the array.  function call .
	
	int guess;
	printf("guess the position of the queen : ");
    scanf("%d", &guess);                           // the problem in the code which result in undefined behaviour is the scanf() function .(wrong syntax /logic).
	                                               // scanf expects a pointer o rreference and not the variable itsself 
	if((arr[guess-1] == 'Q')){
		printf("you win! \n");
		*(money) = 2* (*(money));        // add the money variable.
		if(*(money) == 0){           // win condition if money == 0;
			*(money) = 50 ;
		}
		printf("\nMoney = %d\n\n",*money);
	}
	if((arr[guess-1] != 'Q')){
		printf("Better luck next time .\n");
		printf("\nMoney = %d\n\n",*money);
	}		
	while(*(money) != 0){
		if(*(money) == 0 || *(money) < 0 ){
		    break;
		}
		bet_logic(money);
	}	
}

int shuffle(char arr[]){
	int i;
	
	srand(time(NULL));
	
	for(i=0;i<5;i++){
		int x =rand() % 3;
		int y =rand() % 3;
		
		int temp = arr[0];
		arr[0] = arr[2];
		arr[2] = arr[x];
		arr[y] = temp;
	}
}
