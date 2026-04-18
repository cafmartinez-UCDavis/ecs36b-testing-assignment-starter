# Google Test And Debugging Writeup

##### Project helpers: Copilot, for explanations and walking me through the instructions, specifically when getting started and how to comment out all other files to focus on one test case and testing file at a time, Asking professor for help, and Google AI explainations 

## Things I Thought To Test
1. Thing 1: I want to confirm whether the sorting algorith works in the first place.
2. Thing 2: I want to make sure that the space being allocated by malloc is being allocated properly in the first place and is being freed once done with.
3. Thing 3: Once the original numbers are stored, I want to make sure that the sorted array of numbers is the one being spit out at the end.
4. Thing 4: I want test if the swap/all other smaller functions within the code work and pass my test cases.
5. Thing 5: I need to make sure I properly write my test cases and RC cases so they properly identify where the bugs are.

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
lines 60-70 for sorting.ccp

```c++
Copy of the buggy code: 

void swap(int* a, int* b) {
  /**
 * Swap the values held in a and b.
 * @param a: The address of the first element to swap.
 * @param b: The address of the second element to swap.
 */

  int* temp = a;
  a = b;
  b = temp;
}

```

### How the bug was located

Explain how you found the bug: I found the bug when writing my first couple test cases in the test_swap.cpp, it failed all of the basic and even rapid checks

### Description

Describe the bug: The bug is that the values being passed into the swap function are not being swapped and are just remaining the same.

### Fix

Explain how you fixed the bug 
The original code was only swapping the pointers, or what the pointers were pointing at and not the values. So I dereferenced the pointers to access the value at the location and that fixed the issue
```c++
Copy of the fixed code:
void swap(int* a, int* b) {
  /**
 * Swap the values held in a and b.
 * @param a: The address of the first element to swap.
 * @param b: The address of the second element to swap.
 */

  int temp = *a;
  *a = *b;
  *b = temp;
}
```

### Bug 3

### Location

Line number(s) of the bugs.
29-39 in the sorting.ccp file
```c++
Copy of the buggy code
int* copy_array(int* ar, int len) {
  /**
  * Return a copy of the array
  * @param ar: The array to copy
  * @param len: The length of the array to copy
  * @return: A copy of ar
  */
  
  int* copy = ar;
  return copy;
}
```

### How the bug was located

Explain how you found the bug: I found the bug as while running my test cases in test_copy my array was not being copied but the pointer was.

### Description

Describe the bug

The code was not creating a copy of the array and just assigning something else with the pointer value making it pass some test cases but failing those that tested the contents

### Fix

Explain how you fixed the bug: i fixed the bug by fixing creating a copy array with memory allocated to it then itterating over the previous array and putting it into the new array index by index

```c++
Copy of the fixed code:
int* copy_array(int* ar, int len) {
  /**
  * Return a copy of the array
  * @param ar: The array to copy
  * @param len: The length of the array to copy
  * @return: A copy of ar
  */
  int* copy = new int[len];
  for (int i = 0; i < len; ++i) {
    copy[i] = ar[i];
  }
  return copy;
}
```