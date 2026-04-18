
#include <cstdlib>
#include <string>
#include "gtest/gtest.h"
#include "formatting.h"
#include "test_helpers.h"
#include "rapidcheck/gtest.h"

auto word_generator() {
  return rc::gen::container<std::string>(
      rc::gen::inRange(1, 10),
      rc::gen::inRange('a', 'z' + 1)
  );
}

auto vector_of_ints_to_vector_of_strings(const std::vector<int>& numbers) {
  std::vector<std::string> result;
  result.reserve(numbers.size());
  for (int n : numbers) {
    result.push_back(std::to_string(n));
  }
  return result;
}


TEST(ParseArgsTests, SimpleCheckArgumentsParsedSuccessfully) {
  const char* argv[] = {"prog", "1", "2", "3"};
  int argc = 4;

  int* result = parse_args(argc, const_cast<char**>(argv));

  ASSERT_NE(result, nullptr);
  EXPECT_EQ(result[0], 1);
  EXPECT_EQ(result[1], 2);
  EXPECT_EQ(result[2], 3);

  delete[] result;
}

TEST(ParseArgsTests, SimpleCheckParseNoArgs) {
  const char* argv[] = {"prog"};
  int argc = 1;

  int* result = parse_args(argc, const_cast<char**>(argv));

  EXPECT_EQ(result, nullptr);
}


RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckArgumentsParsedSuccessfully,
              ()
) {
  int len = *rc::gen::inRange(1, 10);
  std::vector<int> values =
      *rc::gen::container<std::vector<int>>(len, rc::gen::arbitrary<int>());

  int argc = len + 1;
  char** argv = new char*[argc];
  argv[0] = const_cast<char*>("prog");

  for (int i = 0; i < len; i++) {
    std::string s = std::to_string(values[i]);
    argv[i + 1] = strdup(s.c_str());
  }

  int* result = parse_args(argc, argv);

  RC_ASSERT(result != nullptr);

  for (int i = 0; i < len; i++) {
    RC_ASSERT(result[i] == values[i]);
  }

  delete[] result;
  for (int i = 1; i < argc; i++) free(argv[i]);
  delete[] argv;
}

RC_GTEST_PROP(ParseArgsTests,
              PropertyCheckParseNoArgs,
              ()
) {
  const char* argv[] = {"prog"};
  int argc = 1;

  int* result = parse_args(argc, const_cast<char**>(argv));

  RC_ASSERT(result == nullptr);
}

