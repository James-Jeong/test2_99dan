#include "local/test2_99dan_l.h"

//////////////////////////////////////
// Local functions
//////////////////////////////////////

/**
 * @fn __inline static void calculate_99dan( int value1, int value2)
 * @brief 구구단 계산을 위한 인라인 함수
 * @param value1 operand 1
 * @param value2 operand 2
 * @return 반환값 없음
 */
__inline static void calculate_99dan(int value1, int value2)
{
	printf("\t| @ (%d) x (%d) = %d\n", value1, value2, (value1 * value2));
}

/**
 * @fn void display_99dan_result( int dan_number, int order_number)
 * @brief 구구단 계산 및 결과를 출력하기 위한 함수
 * @param dan_number 입력받은 단수, 특정 단수를 출력하기 위해 사용된다.
 * @param order_number 출력 순서, 오름차순 또는 내림차순
 * @return 반환값 없음
 */
void display_99dan_result(int dan_number, int order_number)
{
	int loop_index = 1;

	if (order_number == 0)
	{
		for (; loop_index <= MAX_NCAL; loop_index++)
		{
			calculate_99dan(dan_number, loop_index);
		}
	}
	else if (order_number == 1)
	{
		for (loop_index = MAX_NCAL; loop_index > 0; loop_index--)
		{
			calculate_99dan(dan_number, loop_index);
		}
	}
}

/**
 * @fn void input_number( int *dan_number, char *msg, int min, int max)
 * @brief 단수를 입력받기 위한 함수, scanf 사용
 * @param number 입력받을 숫자
 * @param msg 출력문에 사용될 숫자 변수 이름 및 범위
 * @param min 최소 입력 숫자
 * @param max 최대 입력 숫자
 * @return 반환값 없음
 */
void input_number(int *number, char *msg, int min, int max)
{
	int return_value = FAIL;
	while (1)
	{
		if ((*number == DEFAULT_INT) && (return_value == FAIL))
		{
			printf("\t| @ 입력 (%s) \t: ", msg);
			return_value = scanf("%d", number);
			if (return_value == FAIL)
			{
				printf("\t| ! 입력 실패 (%s), 정수가 아닌 문자열 입력\n", msg);
				*number = DEFAULT_INT;
				while (getchar() != '\n')
					;
				continue;
			}
			else if ((*number < min) || (*number > max))
			{
				printf("\t| ! 입력 실패 (%s), 최소:%d / 최대:%d\n", msg, min, max);
				*number = DEFAULT_INT;
				return_value = FAIL;
				continue;
			}
		}
		if ((*number != DEFAULT_INT) && (return_value == SUCCESS))
			break;
	}
}
