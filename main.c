#include "local/test2_99dan_l.h"

/**
 * @fn void main( int argc, char **argv)
 * @brief test2_99dan_t 모듈 구동을 위한 main 프로그램, 구구단 계산 프로그램
 * 1부터 10까지의 범위에서 특정 단수의 구구단을 출력한다.
 * 오름차순 또는 내림차순으로 출력 가능하다.
 * @return 반환값 없음
 */
void main(){
	int dan_number = DEFAULT_INT, order_number = DEFAULT_INT;

	input_number( &dan_number, "단수", 1, 10);
	input_number( &order_number, "출력 순서", 0, 1);
	display_99dan_result( dan_number, order_number);
}

