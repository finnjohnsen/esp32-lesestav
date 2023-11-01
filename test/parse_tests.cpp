#include "unity.h"
#include <string>
using namespace std;

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_func1(void) {
  UnityPrint("Tester bare masse greier");
  UNITY_OUTPUT_CHAR('\n');
  TEST_ASSERT_EQUAL_STRING_MESSAGE("Hei", "Hei", "Hei skal være lik hei");
  TEST_ASSERT_EQUAL_INT(100, 100);
}

void test_parse(void) {
  uint8_t scanData[] = {2, 48, 50, 52, 50, 51, 70, 67, 52, 50, 53, 55, 66, 51, 48, 13, 10, 3};
  for(auto i: scanData){
    UnityPrint(String(i).c_str());
    UNITY_OUTPUT_CHAR('\n');

  }
  UNITY_OUTPUT_CHAR('\n');
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_func1);
  RUN_TEST(test_parse);
  return UNITY_END();
}

// int main(void) {
//   return runUnityTests();
// }