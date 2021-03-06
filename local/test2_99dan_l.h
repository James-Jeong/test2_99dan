#ifndef __TEST2_99DAN_H__
#define __TEST2_99DAN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

//////////////////////////////////////
// Definitions & Macros
//////////////////////////////////////

/** 성공 여부 */
#define SUCCESS 1
/** 실패 여부 */
#define FAIL 0
/** 숫자 정상 입력 확인 여부 */
#define DEFAULT_INT INT_MAX
/** 구구단 진행 최대 개수 */
#define MAX_NCAL 10

//////////////////////////////////////
// Functions
//////////////////////////////////////

void input_number(int *number, char *msg, int min, int max);
void display_99dan_result( int dan_number, int order_number);

#endif // #ifndef __TEST2_99DAN_H__

