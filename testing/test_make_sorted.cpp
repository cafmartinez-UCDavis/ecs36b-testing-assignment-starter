
#include <cstdlib>
#include <vector>
#include "gtest/gtest.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"
#include "test_helpers.h"

TEST(MakeSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int ar[] = {1, 2, 3, 4, 5};
    int len = 5;

    make_sorted(ar, len);

    int expected[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < len; i++) {
      EXPECT_EQ(ar[i], expected[i]);
    }
}

TEST(MakeSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array[] = {9, 7, 5, 3, 1};
    int len = 5;

    make_sorted(array, len);

    int expected[] = {1, 3, 5, 7, 9};
    for (int i = 0; i < len; i++) {
      EXPECT_EQ(array[i], expected[i]);
    }
}


TEST(MakeSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array[] = {4, 1, 7, 3, 2};
    int len = 5;

    make_sorted(array, len);

    int expected[] = {1, 2, 3, 4, 7};
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(MakeSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array[] = {5, 2, 5, 1, 2};
    int len = 5;

    make_sorted(array, len);

    int expected[] = {1, 2, 2, 5, 5};
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

RC_GTEST_PROP(MakeSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    /* Test that after sorting an array, the values are in ascending order
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    RC_PRE(!values.empty());

    int len = values.size();
    int* ar = new int[len];

    for (int i = 0; i < len; i++) {
        ar[i] = values[i];
    }

    make_sorted(ar, len);

    for (int i = 0; i < len - 1; i++) {
        RC_ASSERT(ar[i] <= ar[i + 1]);
    }

    delete[] ar;
}