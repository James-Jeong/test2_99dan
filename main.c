#include "local/test2_99dan_l.h"

/**
 * @fn void main( int argc, char **argv)
 * @brief test2_99dan_t 모듈 구동을 위한 main 프로그램, 구구단 계산 프로그램
 * 1부터 10까지의 범위에서 특정 단수의 구구단을 출력한다.
 * 오름차순 또는 내림차순으로 출력 가능하다.
 * @return 설정하지 않음
 * @param argc 설정하지 않음
 * @param argv 설정하지 않음
 */
void main(){
	int rv = 0;
	int dan_number = 0, order_number = 0;

	rv = test2_99dan_input_dan_number( &dan_number, "dan number(1~10)", 1, 10);
	if( rv < CAL_SUCCESS){
		printf("\t| ! Input dan number error\n");
		return ;
	}

	rv = test2_99dan_input_order_number( &order_number, "order number(0:up/1:down)", 0, 1);
	if( rv < CAL_SUCCESS){
		printf("\t| ! Input order number error\n");
		return ;
	}

	test2_99dan_display_99dan_result( dan_number, order_number);
}

