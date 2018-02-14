
#include "fa_better.h"


void fa_clean_arr(better_float* array) {

    if (array->isMalloc) free(array->array);
}


better_float fa_expanded_get_arr(float* float_array, unsigned size_param, unsigned length) {

    better_float arr;

    arr.len   = length;
    arr.type  = size_param;
    arr.array = float_array;
    arr.isMalloc = false;

    return arr;
}


void fa_set_value(better_float* array, unsigned index, float value) {

    if (index < array->len) {
        array->array[index] = value;
    }

    else {

        char buffer[30];
        
        sprintf(buffer, "set value at index %u", index);
        
        ERROR_FAILED(buffer);
    }
}


float fa_get_value(better_float* array, unsigned index) {

    if (index < array->len) return array->array[index];

    else ERROR_FAILED("get value at given index")
}


better_float fa_del_value(better_float* array, unsigned index) {

    unsigned l_index    = index + 1;
    unsigned new_length = array->len - 1;
    unsigned size       = sizeof(float) * new_length;

    float*   new_array  = malloc(size);
    bool     isSwitched = false;

    if (new_array == NULL) {
        ERROR_FAILED("allocate memory for array");
    }

    else if (l_index >= array->len) {

        char buffer[32];

        sprintf(buffer, "delete value at index %u", index);

        ERROR_FAILED(buffer);
    }

    for (unsigned i = 0; i < new_length; i++) {

        if (i == (l_index - 1)) {
            new_array[i] = array->array[i + 1];
            isSwitched   = true;
        }

        else {

            if (isSwitched) new_array[i] = array->array[i + 1];

            else            new_array[i] = array->array[i];

        }

    }

    better_float replace_arr;

    replace_arr.len   = new_length;
    replace_arr.type  = size;
    replace_arr.array = new_array;
    replace_arr.isMalloc = true;

    return replace_arr;
}


better_float fa_split_arr(better_float* array, unsigned index, unsigned lor) {

    bool isLooping = true;
    bool isCutting = false;

    unsigned lor_checked = ((lor == 0) ? index : (array->len - index));

    unsigned size = sizeof(float) * lor_checked;

    float* new_array = malloc(size);


    for (unsigned i = 0, n = 0; isLooping && i <= array->len; i++) {

        if (i == index) {

            if (lor == 0) isLooping = false;

            else          isCutting = true;

        }

        else {

            if      (lor == 0)  new_array[i] = array->array[i];

            else if (isCutting) new_array[n++] = array->array[i - 1];
        }

    }


    if (array->isMalloc) free(array->array);

    better_float replace_arr;

    replace_arr.len = lor_checked;
    replace_arr.type = size;
    replace_arr.array = new_array;
    replace_arr.isMalloc = true;

    return replace_arr;
}
