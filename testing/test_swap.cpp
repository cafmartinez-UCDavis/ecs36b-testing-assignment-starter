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
    /*
     * Swap two values and see if the swap was successful.
     */
    int a = a_start;
    int b = b_start;
    swap(&a, &b);
    RC_ASSERT(a == b_start);
    RC_ASSERT(b == a_start);
}


RC_GTEST_PROP(SwapTests,
              PropertySwapValuesInArray,
              (const std::vector<int>& values)
) {
    //if there is only 1 index in the array it automatically passes
    if (values.size() < 2) {
        RC_SUCCEED();
    }

    int i = *rc::gen::inRange(0, static_cast<int>(values.size()));
    int j = *rc::gen::inRange(0, static_cast<int>(values.size()));

    auto original = values;
    auto changedVector = values;

    swap(&changedVector[i], &changedVector[j]);

    RC_ASSERT(changedVector[i] == original[j]);
    RC_ASSERT(changedVector[j] == original[i]);

    for (size_t k = 0; k < values.size(); ++k) {
        if (k != static_cast<size_t>(i) && k != static_cast<size_t>(j) ){
            RC_ASSERT(changedVector[k] == original[k]);
        }
    }
    /*
     *
     * Swap two values in an array. See that they swapped and the others did not
     */
}
