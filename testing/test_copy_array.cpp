#include <cstdlib>
#include <vector>
#include <algorithm>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "sorting.h"
#include "test_helpers.h"


#include "rapidcheck/gtest.h"

TEST(CopyArrayTests, SimpleValuesAreSame) {
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int array[] = {1, 2, 3, 4};
    int len = 4;

    int *copy = copy_array(array, len);

    for (int i = 0; i < len; i++) {
      EXPECT_EQ(copy[i], array[i]);
    }
    delete[] copy;

}

TEST(CopyArrayTests, SimpleOriginalDoesNotChange) {
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
    int src[] = {5, 6, 7, 8};
    int len = 4;

    int same_different_copy[] = {5, 6, 7, 8};

    int *copy = copy_array(src, len);

    for (int i = 0; i < len; i++) {
      EXPECT_EQ(src[i], same_different_copy[i]);
    }
    delete[] copy;
}

TEST(CopyArrayTests, SimpleCopyWasMade) {
    /*
     * Check that a copy was actually made
     * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
  int src[] = {9, 8, 7, 6};
  int len = 4;

  int *copy = copy_array(src, len);

  // The copy must be a different pointer
  EXPECT_NE(copy, src);

  // The values must match
  for (int i = 0; i < len; i++) {
    EXPECT_EQ(copy[i], src[i]);
  }

  // Free memory allocated by copy_array
  delete[] copy;
}


RC_GTEST_PROP(CopyArrayTests,
              PropertyValuesAreSame,
              (const std::vector<int>& values)
) {
    int len = values.size();

    int* src = new int[len];
    for (int i = 0; i < len; ++i) {
      src[i] = values[i];
    }
    int *copy = copy_array(src, len);

    for (int i = 0; i < len; i++) {
      RC_ASSERT(copy[i] == src[i]);
    }
    delete[] copy;
    delete[] src;
    /*
     * Check that the values in the copy are the same as the values in the original array.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */
}

RC_GTEST_PROP(CopyArrayTests,
              PropertyOriginalDoesNotChange,
              (const std::vector<int>&values)
) {
    int len = values.size();

    int* src = new int[len];
    for (int i = 0; i < len; ++i) {
      src[i] = values[i];
    }

    int* before_change = new int[len];
    for (int i = 0; i < len; ++i) {
      before_change[i] = values[i];
    }

    int* copy = copy_array(src, len);

    for (int i = 0; i < len; i++) {
      RC_ASSERT(src[i] == before_change[i]);
  }
  delete[] src;
  delete[] before_change;
  delete[] copy;
    /*
     * Check that the  values in the original array did not change.
     * Don't forget to free any memory that was dynamically allocated as part of your test.
     */

}

RC_GTEST_PROP(CopyArrayTests,
              PropertyCopyWasMade,
              (const std::vector<int>&values)
) {
  int len = values.size();

  int* src = new int[len];
  for (int i = 0; i < len; i++) {
    src[i] = values[i];
  }

  int* copy = copy_array(src, len);

  RC_ASSERT(copy != src);


  for (int i = 0; i < len; i++) {
    RC_ASSERT(copy[i] == src[i]);
  }

  if (len > 0) {
    RC_ASSERT(copy + len <= src || src + len <= copy);
  }

  // Clean up
  delete[] copy;
  delete[] src;
    /*
  * Check that a copy was actually made
  * (ar and copy point to different locations in memory and no parts of the two arrays overlap)
  * Don't forget to free any memory that was dynamically allocated as part of your test.
  */

}
