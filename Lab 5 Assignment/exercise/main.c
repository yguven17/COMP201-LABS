#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linkedlist.h"

void test_case1(){
    printf("Test Case 1 - Middle Remove: ");fflush(stdout);
    LinkedList l;
    int arr[] = {3,2,8,5,1};
    LinkedList_init(&l, arr, 5);
    const int r = LinkedList_remove_value(&l, 8);
    const char * expected = "[ 3 2 5 1 ]";
    char resulted[100] = "";
    LinkedList_to_string(&l, resulted);
    if(strcmp(resulted, expected) == 0 && r == 2){
        printf("PASS!\n");
    }else{
        printf("FAILED!\n");
        printf("Expected: %s - Resulted: %s | Expected Return: %d - Returned: %d\n", expected, resulted, 2, r);
    }
}

void test_case2(){
    printf("Test Case 2 - Beginning Remove: ");fflush(stdout);
    LinkedList l;
    int arr[] = {7, 4, 5};
    LinkedList_init(&l, arr, 3);
    const int r = LinkedList_remove_value(&l, 7);
    const char * expected = "[ 4 5 ]";
    char resulted[100] = "";
    LinkedList_to_string(&l, resulted);
    if(strcmp(resulted, expected) == 0 && r == 0){
        printf("PASS!\n");
    }else{
        printf("FAILED!\n");
        printf("Expected: %s - Resulted: %s | Expected Return: %d - Returned: %d\n", expected, resulted, 0, r);
    }
}

void test_case3(){
    printf("Test Case 3 - End Remove: ");fflush(stdout);
    LinkedList l;
    int arr[] = {8, 2, 6, 5, 3};
    LinkedList_init(&l, arr, 5);
    const int r = LinkedList_remove_value(&l, 3);
    const char * expected = "[ 8 2 6 5 ]";
    char resulted[100] = "";
    LinkedList_to_string(&l, resulted);
    if(strcmp(resulted, expected) == 0 && r == 4){
        printf("PASS!\n");
    }else{
        printf("FAILED!\n");
        printf("Expected: %s - Resulted: %s | Expected Return: %d - Returned: %d\n", expected, resulted, 4, r);
    }
}


void test_case4(){
    printf("Test Case 4 - Not Found: ");fflush(stdout);
    LinkedList l;
    int arr[] = {8, 2, 6, 5, 3};
    LinkedList_init(&l, arr, 5);
    const int r = LinkedList_remove_value(&l, 10);
    const char * expected = "[ 8 2 6 5 3 ]";
    char resulted[100] = "";
    LinkedList_to_string(&l, resulted);
    if(strcmp(resulted, expected) == 0 && r == -1){
        printf("PASS!\n");
    }else{
        printf("FAILED!\n");
        printf("Expected: %s - Resulted: %s | Expected Return: %d - Returned: %d\n", expected, resulted, -1, r);
    }
}

int main(int argc, char const *argv[])
{
    test_case1(); // tests for middle remove
    test_case2(); // tests for beginning remove
    test_case3(); // tests for end remove
    test_case4(); // tests for not found
    return 0;
}
