#include <cstdlib>
#include <vector>
#include <algorithm>
#include "test_helpers.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "rapidcheck/gtest.h"


TEST(SwapTests, SimpleSwapTwoValues) {
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = 5;
    int b = 10;
    swap(&a, &b);
    EXPECT_EQ(10, a);
    EXPECT_EQ(5, b);
}

TEST(SwapTests, SimpleSwapValuesInArray) {
    /*
     * Swap a few values in an array.
     * Check that the ones that swapped did swap and the ones that didn't swap
     * are still at the same locations
     */

    int arr[] = {1, 2, 3, 4, 5};
    swap(&arr[1], &arr[3]);
    EXPECT_EQ(4, arr[1]);
    EXPECT_EQ(2, arr[3]);
    EXPECT_EQ(1, arr[0]);
    EXPECT_EQ(3, arr[2]);
    EXPECT_EQ(5, arr[4]);
}

RC_GTEST_PROP(SwapTests,
              PropertySwapTwoValues,
              (int a_start, int b_start)
) {
  (void)a_start;
  (void)b_start;

    /*
     * Swap two values and see if the swap was successful.
     */
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
  (void)values;

    /*
     *
     * Swap two values in an array. See that they swapped and the others did not
     */
}
