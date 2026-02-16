# Ch08 Pointers and Dynamic Storage

## Function pointers

It is possible to take the address of a function and store it in a function pointer.
The pointer can then be used to call the function.

```
int (*Compare)(char*, char*);

Compare = &strcmp;
```

# Ch09 Othe Facilities

## Generic classes

A class such as Set becomes really useful when it is independent of the type of
elements a set may contain: the same class may be used to produce the sets of
integers, reals, strings, etc. Such classes are said to be `generic`.
