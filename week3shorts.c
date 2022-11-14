// RECURSION
// we can consider recursion using the factorial n! which we will call fact(n)
fact(n) = n * fact(n-1);
// all we need is a base case to stop the function from happening forever
// and a recursive case; where the function calls itself but in a way that slightly reduces the problem.
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else 
    {
        return n * fact(n - 1);
    }
}
// So consider fact(3), 3 != 1, hence return 3 * fact(2)
// consider fact(2), 2 != 1, hence return 2 * fact(1)
// consider fact(1), 1 == 1, hence return 1.
// Moving back up through our code then we returned 1, then 2 * 1, then finally we return 3 * 2 * 1 == 6

// MERGE SORT
// use recursion to sort the left half, then right half, then merge those halves, then repeat!
// 
