#include "unity.h"
#include "calculator.h"

void setUp(void) {}
void tearDown(void) {}

void test_add(void)
{
    TEST_ASSERT_EQUAL_INT(5,  add(2,  3));
    TEST_ASSERT_EQUAL_INT(0,  add(-1, 1));
    TEST_ASSERT_EQUAL_INT(0,  add(0,  0));
}

void test_subtract(void)
{
    TEST_ASSERT_EQUAL_INT(2,  subtract(5, 3));
    TEST_ASSERT_EQUAL_INT(-5, subtract(0, 5));
}

void test_multiply(void)
{
    TEST_ASSERT_EQUAL_INT(12,  multiply(3,   4));
    TEST_ASSERT_EQUAL_INT(-10, multiply(-2,  5));
    TEST_ASSERT_EQUAL_INT(0,   multiply(0,  100));
}

void test_divide(void)
{
    double result;
    TEST_ASSERT_EQUAL_INT(0, divide(10.0, 2.0, &result));
    TEST_ASSERT_EQUAL_DOUBLE(5.0, result);

    TEST_ASSERT_EQUAL_INT(0, divide(7.0, 2.0, &result));
    TEST_ASSERT_EQUAL_DOUBLE(3.5, result);
}

void test_divide_by_zero(void)
{
    double result;
    TEST_ASSERT_EQUAL_INT(-1, divide(1.0, 0.0, &result));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_add);
    RUN_TEST(test_subtract);
    RUN_TEST(test_multiply);
    RUN_TEST(test_divide);
    RUN_TEST(test_divide_by_zero);
    return UNITY_END();
}
