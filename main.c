#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Palindrome(const char *, int, int);
int testPalindrome(const char *);


int main(void) {
    puts("Enter a string to be tested as a palindrome:\n");
    fflush(stdout); //needed for puts to be displayed during debug
    char myString[50];
    gets(myString);

    int result = testPalindrome(myString);
    printf("\"%s\" is%s a palindrom\n", &myString, (result ? "" : " not"));

    return 0;
}

/*
 * Base case:
 *
 */
int testPalindrome(const char *myString)
{
    return Palindrome(myString, strlen(myString)-1, 0);
}

// r    a   d   a   r
int Palindrome(const char *myString, int end, int front)
{
    if(front == strlen(myString) / 2)
        return 1; //If the middle character is reached without failing, it's a palindrome
    if(myString[front] == myString[end])
        return Palindrome(myString, end - 1, ++front); //If the first an last letters match, then check the next pair
    else
        return 0; //If there is no match, it wasn't a palindrome.

}