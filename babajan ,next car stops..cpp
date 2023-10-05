#include<iostream>

float calc_s(float,float,float);

int main(){
	float c1;
	std::cout << "enter first cars speed : ";
	std::cin >> c1;
	
	float c2;
	std::cout << "\nenter second cars speed : ";
	std::cin >> c2;
	
	float time;
	std::cout << "\nenter time : ";
	std::cin >> time;
	
	system("cls");
	
	float res = calc_s(c1,c2,time);
	
	std::cout << "time for the slower car to reach the stopping destination of the faster car after stopping of faster car is : " <<res;
	
    return 0;	
}

float calc_s(float a,float b,float c){
	float c1 = (a*c);
	float c2 = (b*c);
	float res;
	if(c1>c2){
	res = (c1-c2)/b;
    }
    else{
    res = (c2-c1)/a;
	}
	
	return res;
}
