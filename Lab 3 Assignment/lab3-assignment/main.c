#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*******  COMP201 LAB3 ASSIGNMENT *******/

//YAKUP ENES GUVEN



/*
 * checks if the contents of string str1 and str2 are equal
 * Use strcmp() function to compare
 * return 1 if equal. Else 0.
 * YOU MAY USE ANY STRING FUNCTION
 */
int equalStr(char str1[], char str2[]){

        // write your code below
        if(strcmp(str1,str2)==0)
        {
                return 1;
        }else{
                return 0;
        }
}



/*
 * DO NOT USE any string functions
 * You can only use strlen()
 * replace first n characters of str1[] with '*'
 * string length will be > n
 * Example: occludeStr("Efehan", 3) = "***han"
 */
char* occludeStr(char str1[], int n)
{

        // write your code below
        int i;
        for(i = 0; i++; i<strlen(str1))
        {
                if(i<n)
                {
                        str1[i]="*";
                }
        }
        return str1;

}


/*
 * find the substring "key" in str
 * DO NOT USE any string functions
 * You can only use strlen()
 * returns the index of "k" of substring "key"
 * returns -1 if not found
 * For example: findKey("this key") == 5;
 * For example: findKey("hello world") == -1;
 */
int findKey(char str[])
{
        // write your code below

        int position,i;
        int len = strlen(str);
        int subLen = strlen(str);
        char strSub[] = "key";

        for(i=0; i<(len); i++)
        {
            position =i;
            if(str[i]==strSub[0] && str[i+1]==strSub[1] && str[i+2]==strSub[2])
            {
                return position;
            }
        }
        return -1;

}

/* Find number of occurrences of word str1 in the sentence str2 (not case sensitive)
 * Returns 0 if not found
 * For Example: numOccur( "WE", "We few, we happy few, we band of brothers") = 3
 * YOU MAY USE ANY STRING FUNCTION
 */
int numOccur(char str1[] ,char str2[])
{
        // write your code below

        int counter,i;
        int len1 = strlen(str1);
        int len2 = strlen(str2);

        for(i=0; i<len2; i++)
        {
                if(toupper(str2[i])==toupper(str1[0]) && toupper(str2[i+1])==toupper(str1[1]))
                {
                counter+=1;
                }
        }
        if(counter>0)
        {
                return counter;
        }else{
                return 0;
        }

}

/* Find the max occuring char in str (case sensitive)
 * For Example: maxOccurChar("We few, we happy few, we band of brothers") = 'e'
 * Do not count whitespaces.
 * DO NOT USE any string functions
 * You can only use strlen()
 */
char maxOccurChar(char str[])
{
        // write your code below
        //first remove all empty spaces
        int a = 0, b = 0;
        while (str[a])
        {
                if (str[a] != ' ')
                {
                        str[b++] = str[a];
                }
                a++;
        }
        str[b] = "\0";

        int counterArray[256] = {0};

        int len = strlen(str);
        int max = 0;
        char result;
        int i;

        for (i = 0; i < len; i++)
        {
                counterArray[str[i]]++;
                if (max < counterArray[str[i]] && counterArray[str[i]] != " " )
                {
                        max = counterArray[str[i]];
                        result = str[i];
                }
        }

        return result;
}

/* Implement the atoi function in the standart C library
 * Atoi Function: Given a string as an input it returns corresponding integer number
 * Note: Ignore whitespace characters.
 * Attention: Check sign bits, if the number starts with a '+' treat it as positive, if it is '-' treat it as negative. If there is no sign it is positive.
 * If the number starts with a char other then whitespace or a number return 0.
 * If a char other than a number or a whitespace is encountered end the algorithm and return the number you have found up to that point.
 * Return 0 if a string representation cannot be formulated.
 * For Example: atoiF("+278") = 278
 * For Example: atoiF("   -15") = -15
 * For Example: atoiF("278 with words") = 278
 * For Example: atoiF("Words and -900") = 0
 * YOU MAY USE ANY STRING FUNCTION.
 * You cannot use atoi() from the standard library (You can use it for testing purposes)
 * Note: We will not test against overflows you can ignore them.
 */
int atoiF(char str1[])
{
        // write your code below

        int num = 0;
        int i = 0;
        int sign = 1;

        while (str1[i] == ' ' || !(str1[i] >= '0' && str1[i] <= '9'))
        {
                i++;
        }

        if (str1[i] == '+' || str1[i] == '-')
        {
                if (str1[i] == '-')
                {
                        sign = -1;
                }
                i++;
        }

        while (str1[i] && (str1[i] >= '0' && str1[i] <= '9'))
        {
                num = num * 10 + (str1[i] - '0');
                i++;
        }

        return sign * num;
}


int main()
{
        //You can test your functions here
        //We will modify the main() when grading
int score = 0;

	char str5[] = "radar\0";
	char str6[] = "radar\0";
	char str7[] = "joke\0";
	char str8[] = "joker\0";
	char str9[] = "Efehan\0";
	char str10[] = "Hello World\0";

	char str11[] = "leads";
	char str12[] = "Fear leads to anger anger leads to hatred hatred leads to conflict conflict leads to suffering";
	char str13[] = "Leads";
	char str14[] = "Fear LEADS to anger anger Leads to hatred hatred leadS to conflict conflict leads to suffering";
	char str15[] = "possible";
	char str16[] = "This is impossible";
	char str17[] = "pasta";
  	
	if (equalStr(str5, str6)==1 && equalStr(str7, str8)==0){
		printf("equalStr test passed!\n");
		score +=5;
	}
	else{
		printf("equalStr test failed!\n");
	}
	
	
	if (findKey("ketchup recipe\0") == -1){
		printf("findKey test1 passed!\n");
		score +=5;
	}
	else{
		printf("findKey test1 failed!\n");
	}

	if (findKey("Did you find the key\0") == 17){
		printf("findKey test2 passed!\n");
		score +=5;
	}
	else{
		printf("findKey test2 failed!\n");
	}
	

	if (strcmp(occludeStr(str9, 3), "***han") == 0)
	{

		printf("occludeStr test1 passed!\n");
		score +=5;
	}
	else{
		printf("occludeStr test1 failed!\n");
	}

	if (strcmp(occludeStr(str10, 5), "***** World") == 0)
	{

		printf("occludeStr test2 passed!\n");
		score +=5;
	}
	else{
		printf("occludeStr test2 failed!\n");
	}

	if (numOccur(str11, str12) == 4)
	{
		printf("numOccur test1 passed!\n");
		score +=10;
	}
	else{
		printf("numOccur test1 failed!\n");
	}

	if (numOccur(str13, str14) == 4)
	{
		printf("numOccur test2 passed!\n");
		score +=10;
	}
	else{
		printf("numOccur test2 failed!\n");
	}

	if (numOccur(str17, str14) == 0)
	{
		printf("numOccur test3 passed!\n");
		score +=5;
	}
	else{
		printf("numOccur test3 failed!\n");
	}

	if(maxOccurChar("Fear leads to anger anger leads to hatred hatred leads to conflict conflict leads to suffering") == 'e')
	{
		printf("maxOccur test passed!\n");
		score +=20;
	}
	else
	{
		printf("maxOccur test failed!\n");
	}
	
	if(atoi("   +5976") == atoiF("   +5976"))

	{
		printf("atoiF test1 passed!\n");
		score +=5;
	}
	else
	{
		printf("atoiF test1 failed!\n");
	}

	if(atoi("-5812with words") == atoiF("-5812with words"))

	{
		printf("atoiF test2 passed!\n");
		score +=5;
	}
	else
	{
		printf("atoiF test2 failed!\n");
	}

	if(atoi("Words 98") == atoiF("Words 98"))

	{
		printf("atoiF test3 passed!\n");
		score +=5;
	}
	else
	{
		printf("atoiF test3 failed!\n");
	}

	if(atoi("25") == atoiF("25"))

	{
		printf("atoiF test4 passed!\n");
		score +=5;
	}
	else
	{
		printf("atoiF test4 failed!\n");
	}

	if(atoi("-53E85") == atoiF("-53E85"))

	{
		printf("atoiF test5 passed!\n");
		score +=5;
	}
	else
	{
		printf("atoiF test5 failed!\n");
	}

	if(atoi("   -2F3") == atoiF("   -2F3"))

	{
		printf("atoiF test6 passed!\n");
		score +=5;
	}
	else
	{
		printf("atoiF test6 failed!\n");
	}
  
	printf("This user's score is: %d\n",score);
	

	
        return 0;
}
