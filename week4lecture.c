// MEMORY

// RGB
// just combines some red, green, and blue

// HEXIDECIMAL
// 0 1 2 3 4 5 6 7 8 9 A B C D E F
// using base-16
// 16^0 == 1, 16^1 == 16, etc
// So 00 == 0, 01 == 1, 02 == 2, ..., 09 == 9, 0A == 10, 0B = 11, ..., 0F = 15
// then 10 == 16, 11 == 17, etc...
// highest you can count with two digits is 255.

// MEMORY
// we count memory bytes by hexidecimal
// usally write hexidecimal by 0x10 (== 16) so we don't get it confused with 10!

// POINTER
// a variable that stores the location of some value
// stores the specific byte in which that value can be found
// recall btye = 8 bits (where bit = a zero or a one)
int n = 50;
int *p = &n;
// &n is the address of n
// *p tells the computer that p isn't an integer its an address (a pointer variable).

// 

