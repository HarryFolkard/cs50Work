// Second Week Using C++

// COMPILING
// rather than using 'make hello' we can use 'clang -o hello hello.c' 
// all make is doing is running clang for us.
// '-o' means ouput the filename as follows. So 'clang -o hello' will output the file hello,
// then we can use './hello' as before
// if we wanted to use get_string we would need to use 'clang -o hello hello.c -lcs50' to include the cs50 library!

// DEBUGGING
// use debug50 ./hello to open the debugger, always stay on the terminal window.
// select the line you want the computer to pause at, then you can move forward from there at your own pace.
// you have to set a breakpoint to use the debugger.
// step over = go to next line; step into = go INTO a function that is declared at the breakpoint.

// TYPES
bool 1 byte
char 1 byte
double 8 bytes
float 4 bytes
int 4 bytes
long 8 bytes 
string ? bytes
// remember there are 8 bits in a byte.
// string isn't really a data type in C!!!

// ARRAYS
int score 1 = 72;
int score 2 = 73;
int score 3 = 33;
// this is long and messy, instead we could use,
int scores[3];
scores[0] = 72;
scores[1] = 73;
scores [2] = 33;
// ^this is better

// STRINGS
// strings are just arrays of characters.
string s = "HI!";
printf("%i %i %i\n", s[0], s[1], s[2]);
// this will print 72 73 33
// strings end with the null character
/0
// which is just a bit of 0's i.e. eight zeros

// Finding Length of a string
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name? ");
    
    int i = 0;
    while (name[i] != '\0')
    {
        i++;
    }
    printf("%i\n", i);
}
// see here how we use the special \0 character to tell us where the string ends.
// OR
#include <string.h>
// because this includes a function that finds the length of a string: strlen

// COMMAND LINE ARGUMENTS
// we've been using 
int main(void)
// where void means no command line arguments
int main(int argc, string argv[])
// means the human inputs a number and a string at the command line - the array can be of any length.
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
// here argv[1] returns the name the user types in at the command line
// e.g. './programmename Harry'
// if we used argv[0] it would return the NAME of the array stored, that is it would retunr argv, argv[2] would return null
// if something goes wrong in main then 'return 1;', if stuff goes well then 'return 0;'
// notice main always had a return value! That's why it was
int main()
// with an int





