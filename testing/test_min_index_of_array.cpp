
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "rapidcheck/gtest.h"
#include "sorting.h"

TEST(MinIndexOfArrayTests, SimpleMinIndexAtFrontOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the front of the array
     */
    int array[] = {1, 2, 4, 8};
    int len = 4;

    int result = min_index_of_array(array, len);
    EXPECT_EQ(0, result);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtEndOfArray) {
    /*
     * See if we can find the index of the minimum value when it is at the end of the array
     */
    int array[] = {5, 2, 9, -4};
    int len = 4;

    int result = min_index_of_array(array, len);
    EXPECT_EQ(result,3);
}

TEST(MinIndexOfArrayTests, SimpleMinIndexAtMiddleOfArray) {
    /*
     * See if we can find the index of the minimum value when it is somewhere
     * in the "middle" of the array.
     */
      int array[] = {5, -2, 9, 4};
      int len = 4;

      int result = min_index_of_array(array, len);
      EXPECT_EQ(result,1);
}

TEST(MinIndexOfArrayTests, SimpleDuplicateMinimums) {
    /*
     * See if we return the index of the first minimum in the array
     * When there are multiple values that are the minimum.
     */
    int array[] = {5, 2, 9, 2, 4};
    int len = 5;

    int result = min_index_of_array(array, len);

    EXPECT_EQ(result,1);
}

TEST(MinIndexOfArrayTests, SimpleArrayDoesNotChange) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    int array[] = {5, 3, 9, 1};
    int before_changes[] = {5, 3, 9, 1};
    int len = 4;

    (void)min_index_of_array(array, len);

    for (int i = 0; i < len; i++) {
        EXPECT_EQ(before_changes[i], array[i]);
    }
}


RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyFindMinIndex,
              (const std::vector<int>& values)) {
    /* Check that the value at the location of the minimum index
     * is not larger than any of the other values in the array
     */
    RC_PRE(!values.empty()); /*Copilot: way of making sure that test cases didnt give an empty array*/

    int len = values.size();

    int* ar = new int[len];
    for (int i = 0; i < len; i++) {
        ar[i] = values[i];
    }

    int idx = min_index_of_array(ar, len);

    // 1. Index must be valid
    RC_ASSERT(idx >= 0);
    RC_ASSERT(idx < len);

    // 2. Value at idx must be <= all others
    for (int i = 0; i < len; i++) {
        RC_ASSERT(ar[idx] <= ar[i]);
    }

    delete[] ar;
}

RC_GTEST_PROP(MinIndexOfArrayTests,
              PropertyArrayDoesNotChange,
              (const std::vector<int>& values)) {
    /*
     * Check that finding the minimum of the array did not change the contents of the array.
     */
    RC_PRE(!values.empty());

    int len = values.size();

    int* ar = new int[len];
    int* before = new int[len];

    for (int i = 0; i < len; i++) {
        ar[i] = values[i];
        before[i] = values[i];
    }

    (void)min_index_of_array(ar, len);

    for (int i = 0; i < len; i++) {
        RC_ASSERT(ar[i] == before[i]);
    }

    delete[] ar;
    delete[] before;
}


