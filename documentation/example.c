
#include "../fa_better.h"

#define ARR_LEN 10

void output_normal_array(float*        array);
void output_better_array(better_float* array);

void showcase_set     (better_float* array);
void showcase_del     (better_float* array);
void showcase_swap    (better_float* array);
void showcase_split   (better_float* array);
void showcase_join    (better_float* array);
void showcase_trim    (better_float* array);
void showcase_double  (better_float* array);
void showcase_reverse (better_float* array);
void showcase_expand  (better_float* array);
void showcase_fit_to  (better_float* array);

int main() {

    float float_array_1[ARR_LEN] = {1, 2, 3, 4.4, 5, 6, 7, 8, 9, 10};

    better_float float_array_2 = fa_get_array(float_array_1);

    output_normal_array( float_array_1);
    output_better_array(&float_array_2);

    showcase_set     (&float_array_2);
    showcase_del     (&float_array_2);
    showcase_swap    (&float_array_2);
    showcase_split   (&float_array_2);
    showcase_join    (&float_array_2);
    showcase_trim    (&float_array_2);
    showcase_double  (&float_array_2);
    showcase_reverse (&float_array_2);

    printf("\nSum of all items in the array: %.f\n", fa_get_sum(&float_array_2));

    showcase_expand  (&float_array_2);
    showcase_fit_to  (&float_array_2);

    fa_clean_arr(&float_array_2);

    return 0;
}


void showcase_set(better_float* array) {

    printf("\noriginal value of float_array_2[0]: %.1f\n", fa_get_value(array, 0));

    fa_set_value(array, 0, 26.4);

    printf("changed value of float_array_2[0]:  %.1f\n", fa_get_value(array, 0));

    output_better_array(array);
}


void showcase_del(better_float* array) {

    *array = fa_del_value(array, 0);

    output_better_array(array);
}


void showcase_swap(better_float* array) {

    fa_swap_values(array, 0, 1);

    output_better_array(array);
}


void showcase_split(better_float* array) {

    *array = fa_split_arr(array, 3, 1);

    output_better_array(array);
}


void showcase_join(better_float* array) {

    float flarr[5] = {20, 40, 50, 70, 33};

    better_float array_2 = fa_get_array(flarr);
    
    *array = fa_join_arr(array, &array_2, 0);

    output_better_array(array);
}


void showcase_trim(better_float* array) {

    *array = fa_trim_arr(array, 3, 1);

    output_better_array(array);
}


//instead of showing off a specific function, this one shows an example of how to join an array to itself.
void showcase_double(better_float* array) {

    array->shouldFree = false;

    better_float float_array_3 = fa_split_arr(array, 0, 1);

    array->shouldFree = true;

    *array = fa_join_arr(array, &float_array_3, 0);

    output_better_array(array);
}


void showcase_reverse(better_float* array) {

    *array = fa_reverse_arr(array);

    output_better_array(array);
}


void showcase_expand(better_float* array) {

    *array = fa_expand_arr(array, 4, 42.4);

    output_better_array(array);
}


void showcase_fit_to(better_float* array) {

    *array = fa_fit_to_arr(array, 10, 42.4);

    output_better_array(array);

    *array = fa_fit_to_arr(array, 20, 43.4);

    output_better_array(array);
}


void output_normal_array(float        *array) {

    printf("-------float normal-------\ncontents:");

    for (int i = 0; i < ARR_LEN;) printf(" %.1f", array[i++]);

    printf("\nlen of array: %d //only accessable through macro/extra variable\n", ARR_LEN);

    printf("sizeof(array): %lu //wrong!\n", sizeof(array));
}


void output_better_array(better_float *array) {

    printf("\n--------better arr--------\ncontents:");

    for (int i = 0; i < array->len;) printf(" %.1f", fa_get_value(array, i++));

    printf("\nlen of array: %u\n", array->len);

    printf("sizeof(array): %d\n", array->size_of);
}
