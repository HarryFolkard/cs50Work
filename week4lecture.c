// MEMORY

// HEXIDECIMAL
// 0 1 2 3 4 5 6 7 8 9 A B C D E F
// using base-16
// 16^0 == 1, 16^1 == 16, etc
// So 00 == 0, 01 == 1, 02 == 2, ..., 09 == 9, 0A == 10, 0B = 11, ..., 0F = 15
// then 10 == 16, 11 == 17, etc...
// highest you can count with two digits is 255.

// MEMORY
// we count memory bytes by hexidecimal, that is we store the location as hexidecimal
// usally write hexidecimal by 0x10 (== 16) so we don't get it confused with 10!

// POINTER
// is a variable that stores the location of some value
// it stores the specific byte in which that value can be found
// [recall btye = 8 bits (where bit = a zero or a one)]
int n = 50;
int *p = &n;
// &n is the address of n, so & is the 'address of' operator
// *p tells the computer that p is an address of an integer (a pointer variable).
// in printf we use %p to print a pointer variable
// once we declared a variable as an int star we can just call it by its name
// that is we can drop the int and the *
int *p = &n;
printf("%p\n", p);
// note how I call the variable p and not *p.
printf("%i\n", *p);
// this prints out 50, it prints out what is found at the addres p
// this is called dereferencing a pointer (the first use was declaring a pointer)

// STRINGS
// a string is really just a pointer to the first character of the string
// then the null (\0) tells us where the string ends
string s == char *s;

// POINTER ARITHMETIC
// as of last week we might have typed
string s = "HI!";
printf("%c\n", s[0]);
printf("%c\n", s[1]);
printf("%c\n", s[2]);
// which would print H I ! with newlines in the console
// now we know without the cs50 library we can use
char *s = "HI!";
printf("%c\n", s[0]);
printf("%c\n", s[1]);
printf("%c\n", s[2]);
// or using the dereference operator we can write,
char *s = "HI!";
printf("%c\n", *s);
printf("%c\n", *(s + 1));
printf("%c\n", *(s + 2));
// because * is the dereference operator: it says go to that address
// and we know arrays are stored in a row in memory
// the + 1 doesnt move one byte, it moves one piece of data along.

// PROBLEM: COPYING STRINGS
string s = get_string("s: ");
string t = s;
t[0] = toupper(t[0]);
printf("s: %s\n", s);
printf("s: %s\n", t);
// Suppose s: hi!, we might think t: Hi! and s stays as hi!
// wrong! both s and t will print as Hi!
// why?
// because when we said t = s, we declared that t represents the same address as s
// they point to the same hi! in memory
// we copied the POINTER s into the pointer t
// the two different pointers store the same address.

// SOLUTION: DYNAMIC MEMORY ALLOCATION
// we can copy a string using malloc and free functions
// malloc = memory allocation
// free returns the memory you've used to your computer
// you need
#include <stdlib.h>
// and you must use both malloc and free together 
char *s = get_string("s: ");
char *t = malloc(strlen(s) + 1);
// here we are asking the computer for 4 bytes of memory (one for each char and one for the \0)
// the + 1 is for the null (\0)
for (int i = 0, n = strlen(s) + 1; i < n; i++)
{
    t[i] = s[i];
}
// or
strcpy(t, s);
// then remember to free it once you are done
free(t);
// if you wanted to store three ints, and int = 4 bytes, hence
int *x = malloc(3 * 4);
// or
int *x = malloc(3 * sizeof(int));
// where the sizeof() just tells us how many bytes it uses.

// MEMORY RELATED BUGS
// run
valgrind ./hello

// SWAP FUNCTIONS
// supppose this code to swap some values
void swap(int a, int b);
int main(void)
{
    int x = 1;
    int y = 2;

    swap(x, y);
    printf("x is %i, you is %i\n", x, y);
}
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
// this won't work in swapping x and y
// this is because variables like ints are passed by value
// hence a and b are just copies of x and y, and while they do indeed swap they don't change x and y
// instead this swap function would be better
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// here we use dereferencing to say,
// 'copy what is at location a into tmp' (tmp = *a)
// 'copy what is at location b into location a' (a* = b*)
// 'copy tmp into location b' (*b = tmp)
// and of course call swap like this,
swap(&x, &y);