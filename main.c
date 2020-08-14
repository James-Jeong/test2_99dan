#include "local/test2_99_l.h"

/**
 * @fn int main( int argc, char **argv)
 * @brief test2_99_t 모듈 구동을 위한 main 프로그램
 * @return none
 * @param argc none
 * @param argv none
 */
int main( int argc, char **argv){
	test2_99_t *cal = test2_99_create();
	if( cal == NULL) return CAL_FAIL;
	test2_99_display( cal);
	test2_99_destroy( &cal);
}

