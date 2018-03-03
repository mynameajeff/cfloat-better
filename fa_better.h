
// INCLUDES:
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//~~~~~~~~~~~~~~~~~~~~~


// MACRO DEFINITIONS:

#define N_ITEMS(x)  (sizeof(x) / sizeof((x)[0]))

#define ERROR_FAILED(arg1) { \
    fprintf(stderr, "[CFB_ARRAY ERROR] failed to %s!\n", arg1); \
    exit(1); \
}

#define fa_get_array(float_array) fa_expanded_get_arr(float_array, sizeof(float_array), N_ITEMS(float_array), false, true)
//~~~~~~~~~~~~~~~~~~~~~


// STRUCTURE DEFINITIONS:

typedef struct {

    float* array;      //self-explanatory

    unsigned size_of;  //sizeof(array)
    unsigned len : 24; //length of array

    bool isMalloc   : 1;
    bool shouldFree : 1;

} better_float;
//~~~~~~~~~~~~~~~~~~~~~


// FUNCTIONS DEFINITIONS:

better_float fa_expanded_get_arr(

    float* float_array, 

    unsigned size_param, 
    unsigned length,

    bool isMalloc,
    bool shouldFree
);

void         fa_set_value   (better_float* array, unsigned index, float value);
float        fa_get_value   (better_float* array, unsigned index);
float        fa_get_sum     (better_float* array);


better_float fa_del_value   (better_float* array, unsigned index);


better_float fa_reverse_arr (better_float* array);

void         fa_clean_arr   (better_float* array);
better_float fa_split_arr   (better_float* array, unsigned index, unsigned lor);

better_float fa_join_arr    (better_float* array_1, better_float* array_2, unsigned lor);
better_float fa_trim_arr    (better_float* array, unsigned len, unsigned lor);
//~~~~~~~~~~~~~~~~~~~~~
