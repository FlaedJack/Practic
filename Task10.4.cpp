#include <iostream>
void printString(char* str)
{
    while (*str != '\0') 
    {
        printf("%c", *str);
        ++str;
    }
}

int main() 
{
    char str[] = "Hello, world!";
    printString(str);
    return 0;
}
