#ifndef __TEST2_99DAN_H__
#define __TEST2_99DAN_H__

//////////////////////////////////////
// definition & macro for test2_99dan_t
//////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

/** 성공 여부 */
#define CAL_SUCCESS 1
/** 실패 여부 */
#define CAL_FAIL 0
/** default value to calculate */
#define DEFAULT_INT INT_MAX
/** default value to calculate */
#define MAX_NCAL 10

/**@brief test2_99dan_t struct */
typedef struct test2_99dan_s test2_99dan_t;
struct test2_99dan_s{
	int val;	/**< dan number to calculate */
	int seq; 	/**< sequence number to print */
};

//////////////////////////////////////
// function for test2_99dan_t
//////////////////////////////////////
test2_99dan_t* test2_99dan_create();
int test2_99dan_init( test2_99dan_t *cal);
void test2_99dan_final( test2_99dan_t *cal);
void test2_99dan_destroy( test2_99dan_t **cal);

void test2_99dan_display( test2_99dan_t *cal);
void test_cal_clear( test2_99dan_t *cal);

#endif // #ifndef __TEST2_99DAN_H__
