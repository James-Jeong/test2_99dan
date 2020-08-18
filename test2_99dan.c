#include "local/test2_99dan_l.h"
//////////////////////////////////////
// static function for test2_99dan_t
//////////////////////////////////////
static void test2_99dan_get_value( test2_99dan_t *cal);
static void test2_99dan_get_seq( test2_99dan_t *cal);
static int test2_99dan_input_data( int *val);
static void test2_99dan_calculate( int val1, int val2);

//////////////////////////////////////
// local function for test2_99dan_t
//////////////////////////////////////

/**
 * @fn test2_99dan_t* test2_99dan_create()
 * @brief function to create test2_99dan_t struct object
 * @param val first value to calculate
 * @param seq second value to calculate
 * @return test2_99dan_t struct object
 */
test2_99dan_t* test2_99dan_create(){
	int rv = CAL_FAIL;

	test2_99dan_t *cal = ( test2_99dan_t*)malloc( sizeof( test2_99dan_t));
	if( cal == NULL){
		printf("\t| ! Fail to allocate test2_99dan_t.\n");
		return NULL;
	}

	rv = test2_99dan_init( cal); if( rv < CAL_SUCCESS){
		printf("\t| ! Fail to initialize test2_99dan_t.\n");
		return NULL;
	}

	return cal;
}

/**
 * @fn int test2_99dan_init( test2_99dan_t *cal)
 * @brief function to initialize test2_99dan_t struct object
 * @param cal test2_99dan_t struct object to initialize
 * @param val first value to calculate
 * @param seq second value to calculate
 * @return success
 */
int test2_99dan_init( test2_99dan_t *cal){
	if( cal != NULL){
		memset( cal, 0, sizeof( test2_99dan_t));
		test2_99dan_get_value( cal);
		test2_99dan_get_seq( cal);
	}
	else return CAL_FAIL;
	return CAL_SUCCESS;
}

/**
 * @fn void test2_99dan_final( test2_99dan_t *cal)
 * @brief function to finalize test2_99dan_t struct object, destroy memory of member objects
 * @param cal test2_99dan_t struct object to finalize
 * @return void
 */
void test2_99dan_final( test2_99dan_t *cal){
}

/**
 * @fn void test2_99dan_destroy( test2_99dan_t **cal)
 * @brief function to detroy memory of test2_99dan_t struct object
 * @param cal test2_99dan_t struct object to destroy
 * @return void
 */
void test2_99dan_destroy( test2_99dan_t **cal){
	test2_99dan_final( *cal);
	free( *cal);
	*cal = NULL;
}

/**
 * @fn void test_cal_clear( test2_99dan_t *cal)
 * @brief function to clear data of test2_99dan_t struct object
 * @param cal test2_99dan_t struct object to clear
 * @return void
 */
void test_cal_clear( test2_99dan_t *cal){
	if( cal != NULL) memset( cal, 0, sizeof( test2_99dan_t));
}

/**
 * @fn void test2_99dan_display( test2_99dan_t *cal)
 * @brief function to calculate & print 99dan result of test2_99dan_t struct object
 * @param cal test2_99dan_t struct object to print
 * @return void
 */
void test2_99dan_display( test2_99dan_t *cal){
	if( cal == NULL) return ;

	int i;
	int seq = cal->seq, val = cal->val;

	printf("\n\t| @ Input value\t: %d\n", val);
	if( seq == 1) for( i = 1; i <= MAX_NCAL; i++) test2_99dan_calculate( val, i);
	else for( i = MAX_NCAL; i > 0; i--) test2_99dan_calculate( val, i);
}

/**
 * @fn static void test2_99dan_get_value( test2_99dan_t *cal)
 * @brief function to get 99dan values of test2_99dan_t struct object
 * @param cal test2_99dan_t struct object to get values
 * @return void
 */
static void test2_99dan_get_value( test2_99dan_t *cal){
	/** return value to check error for val */
	int rv_val = CAL_FAIL;
	cal->val = DEFAULT_INT;

	while( 1){
		if(( cal->val == DEFAULT_INT) && ( rv_val == CAL_FAIL)){
			printf("\t| @ Enter 99dan value\t: ");
			rv_val = test2_99dan_input_data( &cal->val);
			if( rv_val < CAL_SUCCESS) continue;
		}

		if(( cal->val != DEFAULT_INT) && ( rv_val == CAL_SUCCESS)) break;
	}
}

/**
 * @fn static void test2_99dan_get_seq( test2_99dan_t *cal)
 * @brief function to get sequence value of test2_99dan_t struct object
 * @param cal test2_99dan_t struct object to get sequence value
 * @return void
 */
static void test2_99dan_get_seq( test2_99dan_t *cal){
	int i;
	/** return value to check error for seq */
	int rv_seq = CAL_FAIL;
	cal->seq = DEFAULT_INT;

	while( 1){
		if(( cal->seq == DEFAULT_INT) && ( rv_seq == CAL_FAIL)){
			printf("\t| @ Enter sequence number (normal:0, reverse:1)\t: ");
			rv_seq = test2_99dan_input_data( &cal->seq);
			if( rv_seq < CAL_SUCCESS) continue;
			if(( cal->seq != 0) && ( cal->seq != 1)){
				printf("\t| ! Wrong sequence number, value is invalid!\n");
				cal->seq = DEFAULT_INT;
				continue;
			}
		}

		if(( cal->seq != DEFAULT_INT) && ( rv_seq == CAL_SUCCESS)) break;
	}
}

/**
 * @fn static int test2_99dan_input_data( int *val)
 * @brief common function to input data
 * @param val value by scanf function
 * @return success
 */
static int test2_99dan_input_data( int *val){
	int rv = scanf( "%d", val);
	if( rv == CAL_FAIL){
		printf("\t| ! Wrong value, value is not integer!\n");
		*val = DEFAULT_INT;
		while( getchar() != '\n');
		return rv;
	}
	return rv;
}

/**
 * @fn static void test2_99dan_input_data( int val1, int val2)
 * @brief common function to calculate 99dan
 * @param val1 operand value 1
 * @param val1 operand value 2
 * @return void
 */
static void test2_99dan_calculate( int val1, int val2){
	printf("\t| @ (%d) x (%d) = %d\n", val1, val2, ( val1 * val2));
}

