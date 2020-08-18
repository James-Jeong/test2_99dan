#include "local/test2_99_l.h"
//////////////////////////////////////
// static function for test2_99_t
//////////////////////////////////////
static void test2_99_get_value( test2_99_t *cal);
static void test2_99_get_seq( test2_99_t *cal);
static int test2_99_input_data( int *val);
static void test2_99_calculate( int val1, int val2);

//////////////////////////////////////
// local function for test2_99_t
//////////////////////////////////////

/**
 * @fn test2_99_t* test2_99_create()
 * @brief function to create test2_99_t struct object
 * @param val first value to calculate
 * @param seq second value to calculate
 * @return test2_99_t struct object
 */
test2_99_t* test2_99_create(){
	int rv = CAL_FAIL;

	test2_99_t *cal = ( test2_99_t*)malloc( sizeof( test2_99_t));
	if( cal == NULL){
		printf("\t| ! Fail to allocate test2_99_t.\n");
		return NULL;
	}

	rv = test2_99_init( cal); if( rv < CAL_SUCCESS){
		printf("\t| ! Fail to initialize test2_99_t.\n");
		return NULL;
	}

	return cal;
}

/**
 * @fn int test2_99_init( test2_99_t *cal)
 * @brief function to initialize test2_99_t struct object
 * @param cal test2_99_t struct object to initialize
 * @param val first value to calculate
 * @param seq second value to calculate
 * @return success
 */
int test2_99_init( test2_99_t *cal){
	if( cal != NULL){
		memset( cal, 0, sizeof( test2_99_t));
		test2_99_get_value( cal);
		test2_99_get_seq( cal);
	}
	else return CAL_FAIL;
	return CAL_SUCCESS;
}

/**
 * @fn void test2_99_final( test2_99_t *cal)
 * @brief function to finalize test2_99_t struct object, destroy memory of member objects
 * @param cal test2_99_t struct object to finalize
 * @return void
 */
void test2_99_final( test2_99_t *cal){
}

/**
 * @fn void test2_99_destroy( test2_99_t **cal)
 * @brief function to detroy memory of test2_99_t struct object
 * @param cal test2_99_t struct object to destroy
 * @return void
 */
void test2_99_destroy( test2_99_t **cal){
	test2_99_final( *cal);
	free( *cal);
	*cal = NULL;
}

/**
 * @fn void test_cal_clear( test2_99_t *cal)
 * @brief function to clear data of test2_99_t struct object
 * @param cal test2_99_t struct object to clear
 * @return void
 */
void test_cal_clear( test2_99_t *cal){
	if( cal != NULL) memset( cal, 0, sizeof( test2_99_t));
}

/**
 * @fn void test2_99_display( test2_99_t *cal)
 * @brief function to calculate & print 99dan result of test2_99_t struct object
 * @param cal test2_99_t struct object to print
 * @return void
 */
void test2_99_display( test2_99_t *cal){
	if( cal == NULL) return ;

	int i;
	int seq = cal->seq, val = cal->val;

	printf("\n\t| @ Input value\t: %d\n", val);
	if( seq == 0) for( i = 1; i <= MAX_NCAL; i++) test2_99_calculate( val, i);
	else if( seq == 1) for( i = MAX_NCAL; i > 0; i--) test2_99_calculate( val, i);
}

static void test2_99_get_value( test2_99_t *cal){
	/** return value to check error for val */
	int rv_val = CAL_FAIL;
	cal->val = DEFAULT_INT;

	while( 1){
		if(( cal->val == DEFAULT_INT) && ( rv_val == CAL_FAIL)){
			printf("\t| @ Enter 99dan value\t: ");
			rv_val = test2_99_input_data( &cal->val);
			if( rv_val < CAL_SUCCESS) continue;
		}

		if(( cal->val != DEFAULT_INT) && ( rv_val == CAL_SUCCESS)) break;
	}
}

static void test2_99_get_seq( test2_99_t *cal){
	int i;
	/** return value to check error for seq */
	int rv_seq = CAL_FAIL;
	cal->seq = DEFAULT_INT;

	while( 1){
		if(( cal->seq == DEFAULT_INT) && ( rv_seq == CAL_FAIL)){
			printf("\t| @ Enter sequence number (normal:0, reverse:1)\t: ");
			rv_seq = test2_99_input_data( &cal->seq);
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

static int test2_99_input_data( int *val){
	int rv = scanf( "%d", val);
	if( rv == CAL_FAIL){
		printf("\t| ! Wrong value, value is not integer!\n");
		*val = DEFAULT_INT;
		while( getchar() != '\n');
		return rv;
	}
	return rv;
}

static void test2_99_calculate( int val1, int val2){
	printf("\t| @ (%d) x (%d) = %d\n", val1, val2, ( val1 * val2));
}

