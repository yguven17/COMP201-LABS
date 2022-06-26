#include <stdio.h>


// Name: YAKUP ENES GUVEN
// Student Id: 64045
// Date: 29.11.2021



// Please provide your answers here:
// 1.3.1

//a : there is no need for using add and addl that uses registar because there is two constatn compiler handeling calcuşations without any functions

//b : memory for the allocated values will be free and and values for a and b will not be accesible

int sumAndProd(int x, int y) {
	// Write your code here
	
	int sum,product;
	sum = x + y;
	product= x*y;
	if(sum>product){
		return sum;
	}
	else{
		return product;
	}

}

int first10() {
	// Write your code here
    
	int sum = 0;
	int i = 0;

	while(i<=9){
		sum += i;
		i+=2;
	}
	return sum;
}

int main(){

   if (sumAndProd(2,2) == 4 && sumAndProd(6,10) == 60 && sumAndProd(1,2) == 3){
	   printf("sumAndProd test passed! \n");
   }
   else{
     printf("sumAndProd test failed:( \n");
   }
   
   if (first10() == 20){
	   printf("first10 test passed! \n");
   }
   else{
     printf("first10 test failed:( \n");
   }
   return 0;
}
