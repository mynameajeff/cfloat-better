
#include "fa_better.h"

#define ARR_LEN 10

void output_normal_array(float*        array);
void output_better_array(better_float* array);

void showcase(better_float* array);


int main() {

    float float_array_1[ARR_LEN] = {1, 2, 3, 4.4, 5, 6, 7, 8, 9, 10};

    better_float float_array_2 = fa_get_array(float_array_1);

    output_normal_array( float_array_1);
    output_better_array(&float_array_2);

    showcase(&float_array_2);

    return 0;
}


void showcase(better_float* array) {

    printf("\noriginal value of float_array_2[0]: %.1f\n", fa_get_value(array, 0));

    fa_set_value(array, 0, 26.4);

    printf("changed value of float_array_2[0]:  %.1f\n", fa_get_value(array, 0));

    output_better_array(array);

    *array = fa_del_value(array, 0);

    output_better_array(array);

    *array = fa_split_arr(array, 3, 1);

    output_better_array(array);
    
    fa_clean_arr(array);

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

    printf("sizeof(array): %d\n", array->type);
}
