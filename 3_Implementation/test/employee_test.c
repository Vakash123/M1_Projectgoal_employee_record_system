/**
 * @file employee_test.c
 * @author vankadari akash
 * @brief : Running the test cases
 * @version 0.1
 * @date 2021-09-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "unity.h"
#include <position.h>

#include <main.h>
#define PROJECT_NAME    "Employee_Record_System"


void position(void);


void setUp(){}

void tearDown(){}


int main()
{

  UNITY_BEGIN();


  RUN_TEST(position);
  


  return UNITY_END();
}


void position(void) {
  TEST_ASSERT_EQUAL(20 40, position(20,40));
  
 
  TEST_ASSERT_EQUAL(20 42, position(20,40));
}
