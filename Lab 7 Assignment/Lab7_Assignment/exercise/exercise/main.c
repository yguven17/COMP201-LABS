#include <stdio.h>

/* 
Draw the snapshots of the runtime stack at various points indicated by comments in the code.asm file
For the unknown variable names, you can use x, y, z etc. 

1) Draw the snapshot of the runtime stack before the call to f
ANSWER: FILL HERE

2) Draw the snapshot of the runtime stack inside f function (when main initially calls it)
ANSWER: FILL HERE 

3) Draw the snapshot of the runtime stack after the call to f
ANSWER: FILL HERE
*/

int f(int num) {
    // FILL HERE

	int a = num;
	int i = 1;

	if(num > 1){
		num -= 1;
		i = num;
		f(i);
		z *= num;
	}
	
	i = z;
	return i;
	

	
}

int main(){
    int res = f(5);
    printf("f(5) = %d", res);
}

