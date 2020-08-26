#ifndef __TEST2_99DAN_H__
#define __TEST2_99DAN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

//////////////////////////////////////
// Definitions & Macros for test2_99dan_t
//////////////////////////////////////

/** 성공 여부 */
#define CAL_SUCCESS 1
/** 실패 여부 */
#define CAL_FAIL 0
/** 숫자 정상 입력 확인 여부 */
#define DEFAULT_INT INT_MAX
/** 구구단 진행 최대 개수 */
#define MAX_NCAL 10

//////////////////////////////////////
// Functions for test2_99dan_t
//////////////////////////////////////

void test2_99dan_input_dan_number( int *dan_number, char *msg, int min, int max);
void test2_99dan_input_order_number( int *order_number, char *msg, int min, int max);
void test2_99dan_display_99dan_result( int dan_number, int order_number);

#endif // #ifndef __TEST2_99DAN_H__

