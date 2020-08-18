#include "local/test2_99dan_l.h"
//////////////////////////////////////
// static function for test2_99dan_t
//////////////////////////////////////
static int test2_99dan_input_number( int *number, char *msg, int min, int max);
static void test2_99dan_calculate_99dan( int dan_number1, int dan_number2);

//////////////////////////////////////
// local function for test2_99dan_t
//////////////////////////////////////
/**
 * @fn void test2_99dan_display_99dan_result( int dan_number, int order_number)
 * @brief 구구단 계산 및 결과를 출력하기 위한 함수
 * @param dan_number 입력받은 단수, 특정 단수를 출력하기 위해 사용된다.
 * @param order_number 출력 방향, 오름차순 또는 내림차순
 * @return 설정하지 않음
 */
void test2_99dan_display_99dan_result( int dan_number, int order_number){
	int i;
	if( order_number == 0) for( i = 1; i <= MAX_NCAL; i++) test2_99dan_calculate_99dan( dan_number, i);
	else if( order_number == 1) for( i = MAX_NCAL; i > 0; i--) test2_99dan_calculate_99dan( dan_number, i);
}

/**
 * @fn int test2_99dan_input_dan_number( int *dan_number, char *msg, int min, int max)
 * @brief 구구단 숫자를 입력받는 함수
 * @param dan_number 입력받을 단수
 * @return 입력 성공 여부
 */
int test2_99dan_input_dan_number( int *dan_number, char *msg, int min, int max){
	int rv = CAL_FAIL;
	*dan_number = DEFAULT_INT;
	rv = test2_99dan_input_number( dan_number, msg, min, max);
	return rv;
}

/**
 * @fn int test2_99dan_input_order_number( int *order_number, char *msg, int min, int max)
 * @brief 출력 방향 숫자를 입력받는 함수
 * @param order_number 입력받을 출력 방향
 * @return 입력 성공 여부
 */
int test2_99dan_input_order_number( int *order_number, char *msg, int min, int max){
	int rv = CAL_FAIL;
	*order_number = DEFAULT_INT;
	rv = test2_99dan_input_number( order_number, msg, min, max);
	return rv;
}

/**
 * @fn static int test2_99dan_input_number( int *dan_number, char *msg, int min, int max)
 * @brief 단수를 입력받기 위한 함수, scanf 사용
 * @param number 입력받을 숫자, 주소값을 넘겨받음
 * @param msg 출력문에 사용될 숫자 변수 이름
 * @param min 최소 입력 숫자
 * @param max 최대 입력 숫자
 * @return 성공 여부
 */
static int test2_99dan_input_number( int *number, char *msg, int min, int max){
	int rv = CAL_FAIL;
	while( 1){
		if(( *number == DEFAULT_INT) && ( rv == CAL_FAIL)){
			printf("\t| @ Enter %s number\t: ", msg);
			rv = scanf( "%d", number);
			if( rv < CAL_SUCCESS){
				printf("\t| ! Wrong %s, %s is not integer!\n", msg, msg);
				*number = DEFAULT_INT;
				while( getchar() != '\n');
				continue;
			}
			else if(( *number < min) || ( *number > max)){
				printf("\t| ! Wrong %s number, value is invalid!\n", msg);
				*number = DEFAULT_INT;
				rv = CAL_FAIL;
				continue;
			}
		}
		if(( *number != DEFAULT_INT) && ( rv == CAL_SUCCESS)) break;
	}
	return rv;
}

/**
 * @fn static void test2_99dan_calculate_99dan( int value1, int value2)
 * @brief 구구단 계산을 위한 함수
 * @param dan_number1 operand 1
 * @param dan_number1 operand 2
 * @return 설정하지 않음
 */
static void test2_99dan_calculate_99dan( int value1, int value2){
	printf("\t| @ (%d) x (%d) = %d\n", value1, value2, ( value1 * value2));
}

