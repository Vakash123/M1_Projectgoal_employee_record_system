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

/* Prototypes for all the test functions */
void position(void);


/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(position);
  

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void position(void) {
  TEST_ASSERT_EQUAL(20 40, position(20,40));
  
  /* Dummy fail*/
  TEST_ASSERT_EQUAL(20 42, position(20,40));
}
