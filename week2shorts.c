// FUNCTIONS
// declare function
int multiplyTwoFloats(float y, float x);
// define function
float multiplyTwoFloats(float y, float x)
{
    return y*x;
}

// VARIABLE SCOPE
// local variables can only be accessed only in the function in which they are created.
// global variables can be accessed by any function in the program.
// Example
#include <stdio.h>
int triple(int local1);

float global = 0.51;

int main(void)
{
    int local1
}

int triple(int local2)
{
    return local2 + 4;
}
// here local1 only exists in main, local2 only exists in triple, while global exists everywhere.
// local variables are passed y value that is it is copies of them that are passed into other functions.
// Example
int main(void)
{
    int x = 1;
    int y;
    y = increment(x);
    printf("x is %i, y is %i\n", x, y);
}
int increment(int x)
{
    x++;
    return x;
}
// this prints 'x is 1, y is 2' because we are passing a COPY of x to increment, hence increment isn't affecting the value of x we have in main.

// ARRAYS
// used to hold values of the same data type at contiguous memory locations 
// arrays are made up of elements, each of which is accessed by the index
// indexes start from 0, NOT FROM 1.
float menuPrices[6];
// this declares an array of 6 floats.
bool truthtable[10];
// this declares an array of 10 booleans.
bool battleship[10][10];
// you can choose to think of this as a 10x10 grid, although in memory it's a 100 element array!
// Individual Element Intialisation
bool truthtable[3];
truthtable[0] = false;
truthtable[1] = true;
truthtable[2] = false;
// Instantiation intialisation
bool truthtable[] = { false, true, false };
// Must copy each individual element to copy one array to another. Do this will a for loop.
// ARRAYS ARE PASSED BY REFERENCE, not by value.

