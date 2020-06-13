/** ----------------------------------------------------------
 *  Ebeling, George Homework 2 Part 2-1
 *  CIS 241 - Prof Bhuse
 *  This program asks the user for a string, and then verifies
 *  if that string is a palindrome.
 *  ----------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STRINGSIZE 10

int Palindrome(const char *, int, int);
int testPalindrome(const char *);
char *GetUserInput();

int main(void) {
    char *myString;
    myString = GetUserInput();

    int result = testPalindrome(myString);

    printf("\"%s\" is%s a palindrome\n", myString, (result ? "" : " not"));

    return 0;
}

/**
 * Reads the user input and returns a string.
 * @return A character pointer to the string.
 */
char *GetUserInput(){

    size_t size = STRINGSIZE;
    char *str;
    int ch;
    size_t len;

    str = realloc(NULL, sizeof(char)*size);//size is start size

    for(len = 0; (EOF!=(ch=getc(stdin)) && ch != '\n'); len++){
        str[len]=ch;

        if(len==size-1)
        {
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';
    return realloc(str, sizeof(char)*len);
}

/**
 * Check if a string is a palindrome while ignoring whitespace and punctuation.
 * @param myString String to check
 * @return True if the string is a palindrome.
 */
int testPalindrome(const char *myString)
{
    return Palindrome(myString, strlen(myString)-1, 0);
}

/**
 * Check if a string is a palindrome. Whitespace and punctuation is ignored in the check.
 * @param myString String to check
 * @param end Last index of the pair
 * @param front First index of the pair
 * @return True if the string is a palindrome.
 */
int Palindrome(const char *myString, int end, int front)
{
    if(front == strlen(myString) / 2)
        return 1; //If the middle character is reached without failing, it's a palindrome

    if(isspace(myString[front]) || ispunct(myString[front])) return Palindrome(myString, end, front+1); //If front is white space or punctuation skip it
    if(isspace(myString[end]) || ispunct(myString[end])) return Palindrome(myString, end-1, front); //if end is white space or punctuation skip it

    if(myString[front] == myString[end])
        return Palindrome(myString, end-1, front+1); //If the first an last letters match, then check the next pair
    else
        return 0; //If there is no match, it isn't a palindrome.
}