# Google Test And Debugging Writeup

## Things I Thought To Test
1. Thing 1: I want to confirm whether the sorting algorith works in the first place.
2. Thing 2: I want to make sure that the space being allocated by malloc is being allocated properly in the first place and is being freed once done with.
3. Thing 3: Once the original numbers are stored, I want to make sure that the sorted array of numbers is the one being spit out at the end.
...

## Bugs

### Bug 1: multiple bugs before I could even test my first testing case, 

### Location: compiler issues in sorting.ccp and formatting.ccp

Line number(s) of the bugs.
Bug 1: sorting.ccp line 29, sorting. ccp line 36
```c++
bug 1: //int* copy_array(int* ar, int len) {
    //sscanf(argv[i], "%d", ar_out[i]);
```

### How the bug was located

Explain how you found the bug

Bug 1: Located once I tried to run the test_swap.ccp file and found in the terminal telling me I had issues with the main code's signature(the code itself) and not just the logic

### Description

Describe the bug

Compiler issues when trying to run my first test case

### Fix 

Explain how you fixed the bug

I called len with dummy function just so the compiler would ignore it.
Then I made ar_out[i] use a pointer instead of an int

```c++
Copy of the fixed code:
//(void)len;
//sscanf(argv[i], "%d", &ar_out[i]);
```

### Bug 2

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```

### Bug 3

### Location

Line number(s) of the bugs.

```c++
Copy of the buggy code
```

### How the bug was located

Explain how you found the bug

### Description

Describe the bug

### Fix

Explain how you fixed the bug

```c++
Copy of the fixed code
```