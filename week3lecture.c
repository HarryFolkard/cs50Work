
// EFFICIENCY
// Big O notation = longest number of steps
// Big Omega notation = shortest number of steps
// Big Theta notation = when Big O == Big Theta


// ARRAYS
// define like this
string names[] = { "harry", "helena", "alice"};
int ages[] = { 21, 21, 19};


// DATA STRUCTURES
// works using type def
typedef struct 
{
    ...
}
nameOfDataType;
// example: data type called person that contains names and ages
typedef struct 
{
    string name;
    int age;
}
person;
// This typedef ^^ needs to go at the top of the file, it is a prototype/declaration
// Then we can use the typedef people as below,
person people[2];

people[0].name = "Harry";
people[0].age = 21;

people[1].name = "Helena";
people[1].age = 21;
// here we have made a data structure of type person called people


// RECURSION
// a programming technique where a function calls itself,
// we do this by calling the functions name inside the function itself.
// example: first here is a function that will print a short of pyramid based on an input height n
void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
// example: using recursion
void draw(int n)
{
    if (n <= 0)
    {
        return;
    }
    
    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
// 


// MERGE SORT
// total run time is nlog(n) and log(n) is smaller than n, so its faster than selection sort or bubble sort.


