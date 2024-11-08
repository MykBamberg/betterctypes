## betterctypes

This simple header file defines macros that allow for easily readable 
left-to-right type specifiers for arrays and function pointers.

### Arrays

Traditional C
```c
int array[128];
const int* array[128];
int* const array[128];
const int* const array[128];
```

betterctypes
```c
arr(/* type */ int, /* length */ 128) array;
arr(const int*, 128) array;
const arr(int*, 128) array;
const arr(const int*, 128) array;
```

### Function pointers

Traditional C
```c
void (*function_pointer)(int, int);
void (*function_pointer)(int, int (*)(int));
void (*(*function_pointer)(int))(int);
```

betterctypes
```c
fn(/* return type */ void, /* parameter types */ int, int) function_pointer;
fn(void, int, fn(int, int)) function_pointer;
fn(fn(void, int), int) function_pointer;

/* new possibility */
fn(void, int) func1, func2;
```
