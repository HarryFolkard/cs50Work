// HEXADECIMAL
// it's a base-16 counting system
0 1 2 3 4 5 6 7 8 9 A B C D E F 
// so A == 10, B == 11, C == 12, D == 13, E == 14, F == 16
// why hexadecimal? because base-16 means we can map 4 bits (binary 0s or 1s) to a single hexidecimal digit.
Decimal : Binary : Hex
      0 : 0000 : 0x0
      1 : 0001 : 0x1
      2 : 0010 : 0x2
      3 : 0011 : 0x3
      4 : 0100 : 0x4
        ...
      9 : 1001 : 0x9
     10 : 1010 : 0xA
     11 : 1011 : 0xB 
        ...
     15 : 1111 : 0xF
// prefix with 0x because otherwise hexadecimal and decimal can be ambiguous 

// POINTERS
// up until now we have always passed data by value - that is we have passed a copy of that data between functions 
// (except when we have been using arrays)
// now with pointers we can pass the ACTUAL VARIABLE ITSELF, hence rather than changing a copy we can change the real thing !
// POINTER == AN ADDRESS
// pointers are addresses to places in memory where variables live
int k;
k = 5;
int* pk;
pk = &k;
// &k == where k is in memory, it is the address of k.
// pk hence contains where k is in memory.
// A pointers VALUE is memory address, and TYPE describes the data located at that memory address
// so pk stores the location at which k is stored, and its type is an int because k is an int
// always set the pointer value to NULL if you aren't immediately using it.
int* px, py, pz;
// this won't work ^^ you need to use the star each time.
int* px, *py, *pz;
// this ^^ will work.

// & OPERATOR
// if x is an int, then &x is the pointer-to-int whose value is the address of x
// if arr is an array of doubles, then &arr[i] is the pointer-to-double who value is the address of the ith element of arr


// POINTERS AND PASSING VARIABLES: DEREFERENCING
// * is the dereference operator - it GOES TO THE ADDRESS
// *pk goes to the address pk, and there you'll find the int 5

// SUMMARY ABOUT POINTERS
int* p;
// value of p is an address.
*p
// value of p is what is at the address p, the int at that address.

// DEFINING CUSTOM TYPES
typedef <oldname> <newname>;
// example
struct car 
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engineSize;
};

typdef struct car car_t;
// better use example
typedef car 
{
    int year;
    char model[10];
    char plate[7];
    int odometer;
    double engineSize;
}
car_t;

// DYNAMIC MEMORY ALLOCATION
// dynamically allocate memory to the heap
malloc(4)
// will give you 4 bytes from the heap
// malloc returns a pointer, if it can't give you the memory then it returns the NULL pointer
// statically obtain an integer
int x;
// dynamically obtain an integer
int* px = malloc(sizeof(int));
// then dereference px to access that memory.
// array of floats on the heap
int x = get_int();
float* heapArray = malloc(x * sizeof(float));
// must free memory that you dynamically allocate.
free(px);
free(heapArray);

// DYNAMIC MEMORY EXAMPLE
int m;
int* a;
int* b = malloc(sizeof(int));
// m is an integer on the stack
// a is a pointer-to-an-integer on the stack
// b in a pointer-to-an-integer on the stack that points to a piece of unnamed memory on the heap
a = &m;
// a points to m
a = b;
// now a points where b points, so they both point to some memory on the stack
m = 10;
*b = m + 2;
// dereferencing! in the memory pointed to by b we store m + 2, (12)
free(b);
// give the memory back to the system
*a = 11;
// now I am accessing memory I shouldn't hence segmentation fault.

// CALL STACK
// really great video that explains more about recursion

// FILE POINTERS
// common file pointer functions in <stdio.h>
fopen() fclose() fgetc() fputc() fread() fwrite()
// all of them accept file pointer
FILE*
// as one of their parameters, except
fopen()
// which is used to get a file pointer in the first place

fopen()
// opens a file and returns file pointer to it, check pointer value is not NULL
FILE* ptr = fopen("<filename>", "<operation>");

// operations: "r" = reads file, "w" writes files (writes over the file), "a" appending files (adds to the end of the file)
fclose(<file pointer);
// closes file

fgetc();
// reads and returns first char from file and stores in variable
char ch = fgetc(<file pointer>);
// must open file before we do this

fputc();
// writes a single character to a file
fputc('<character>', <file pointer>);

fread(<buffer>, <size>, <qty>, <file pointer>);
// reads <qty> units of <size> from the file pointed to and stores them in memory
// in a buffer (usually an array) pointed to by <buffer>
// example 1:
int arr[10];
fread(arr, sizeof(int), 10, pointer);
// reading 10 times 4 bytes (40 bytes) of information 
// from the file pointed to by pointer and storing them in arr
// example 2:
char c;
fread(&c, sizeof(char), 1, pointer);
// recall first arg <buffer> is a pointer
// the name of an array is a pointer so that works
// but if we want to store in a char or int we need to give 
// the location (address) of that char or int
// hence we need to use &

fwrite(<buffer>, <size>, <qty>, <file pointer>);
// writes <qty> units of <size> to the file pointed to
// from a buffer (usually an array) pointed to by <buffer>
// example 1:
int arr[10];
fwrite(arr, sizeof(int), 10, pointer);
// the information goes from buffer to the file

// also useful
fgets() fputs()
// reads and writes full strings
fprintf()
// writes a string to file, can use %i etc in this
fseek()
