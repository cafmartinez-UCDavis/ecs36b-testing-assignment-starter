
#include <cstdlib>
#include "gtest/gtest.h"
#include "sorting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

TEST(GetSortedTests, SimpleSortSortedArray) {
    /*
     * Check that we can sort an array that is already sorted.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

    int array[] = {1, 2, 3, 4, 5};
    int len = 5;

    int* sorted = get_sorted(array, len);

    int expected[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < len; i++) {
      EXPECT_EQ(sorted[i], expected[i]);
    }

    delete[] sorted;
}

TEST(GetSortedTests, SimpleSortReverseSortedArray) {
    /*
     * Check that we can sort an array that is reverse sorted order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array[] = {9, 7, 5, 3, 1};
    int len = 5;

    int* sorted = get_sorted(array, len);

    int expected[] = {1, 3, 5, 7, 9};
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(sorted[i], expected[i]);
    }

    delete[] sorted;
}

TEST(GetSortedTests, SimpleSortAverageArray) {
    /*
     * Check that we can sort an array where the elements in it are in random order.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array[] = {4, 1, 7, 3, 2};
    int len = 5;

    int* sorted = get_sorted(array, len);

    int expected[] = {1, 2, 3, 4, 7};
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(sorted[i], expected[i]);
    }

    delete[] sorted;
}

TEST(GetSortedTests, SimpleSortArrayWithDuplicates) {
    /*
     * Check that we can sort an array where there are duplicate elements in it.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array[] = {5, 2, 5, 1, 2};
    int len = 5;

    int* sorted = get_sorted(array, len);

    int expected[] = {1, 2, 2, 5, 5};
    for (int i = 0; i < len; i++) {
        EXPECT_EQ(sorted[i], expected[i]);
    }

    delete[] sorted;
}

TEST(GetSortedTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the original array was not modified.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array[] = {4, 1, 7, 3, 2};
    int before_change[] = {4, 1, 7, 3, 2};
    int len = 5;

    int* sorted = get_sorted(array, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(array[i], before_change[i]);
    }

    delete[] sorted;
}

TEST(GetSortedTests, SimpleCopyWasMade) {
    /*
     * Check that the sorted array is copy of the original array in sorted order.
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int ar[] = {3, 1, 2};
    int len = 3;

    int* sorted = get_sorted(ar, len);

    // Different memory
    EXPECT_NE(sorted, ar);

    // No overlap
    for (int i = 0; i < len; i++) {
        EXPECT_NE(&sorted[i], &ar[i]);
    }

    delete[] sorted;
}


RC_GTEST_PROP(GetSortedTests,
              PropertyAfterSortingValuesAreInAscendingOrder,
              ( std::vector<int> values)
) {
    RC_PRE(!values.empty());

    int len = values.size();
    int* array = new int[len];

    for (int i = 0; i < len; i++) {
        array[i] = values[i];
    }

    int* sorted = get_sorted(array, len);

    for (int i = 0; i < len - 1; i++) {
        RC_ASSERT(sorted[i] <= sorted[i + 1]);
    }

    delete[] array;
    delete[] sorted;
}

RC_GTEST_PROP(GetSortedTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    RC_PRE(!values.empty());

    int len = values.size();
    int* array = new int[len];
    int* before = new int[len];

    for (int i = 0; i < len; i++) {
        array[i] = values[i];
        before[i] = values[i];
    }

    int* sorted = get_sorted(array, len);

    for (int i = 0; i < len; i++) {
        RC_ASSERT(array[i] == before[i]);
    }

    delete[] array;
    delete[] before;
    delete[] sorted;
}

RC_GTEST_PROP(GetSortedTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
    RC_PRE(!values.empty());

    int len = values.size();
    int* array = new int[len];

    for (int i = 0; i < len; i++) {
        array[i] = values[i];
    }

    int* sorted = get_sorted(array, len);

    // Different memory
    RC_ASSERT(sorted != array);

    // No overlapping elements
    for (int i = 0; i < len; i++) {
        RC_ASSERT(&sorted[i] != &array[i]);
    }

    delete[] array;
    delete[] sorted;
}

