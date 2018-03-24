This file contains the notes/explanations for the various functions, macros and other things.


## MACROS:

### fa_get_array(float_array)
  This macro should be used to get a `better_float` instance, of which is derived from a structure.
  The instance will contain the array, the length of the array, and the `sizeof(array)`.

### ERROR_FAILED(arg1)
  This macro would be called internally if something were to have gone wrong, 
  printing an error message to stderr and calling `exit()`.

### N_ITEMS(x)
  This macro detemines the number of items within a given array.


## BETTER_FLOAT MEMBERS:

### float* array;
  This is where the float array is stored.
  
### unsigned int size_of;
  This would contain the `sizeof(array)` value;
  
### unsigned int len : 24;
  This would contain the length of the array member, 
  and is a bitfield of 24 bits to allow the structure to be 16 bytes in size, and not 24 bytes.

### bool isMalloc : 1;
  This would contain either `true` or `false`, and is used to determine if the instance was created directly, or internally malloc'd. This is needed to avoid most memory leaks.
  It is a bitfield of size 1.

### bool shouldFree : 1;
  This is by default `true`, but can be changed to `false` by the user if desired.
  The point of it is so that when an instance of `better_float` is passed to a function that returns an altered version of that instance's contents in a new instance, you can now decide if you want it to free the instance's array, allowing you to mix and match different instances instead of just influencing one all the time. It also influences the behavior of `fa_clean_arr()` the same way.
  It is a bitfield of size 1.

## FUNCTIONS:

### void fa_set_value(better_float* array, unsigned index, float value);
  This function allows you to set an individual value within the `better_float` instance.
  
### float fa_get_value(better_float* array, unsigned index);
  This function allows you to retrieve an individual value from the `better_float` instance.

### float fa_get_sum(better_float* array);
  This function allows you to retrieve the sum of all values within the `better_float` instance.

### void fa_swap_values(better_float* array, unsigned index_base, unsigned index_sub);
  This function allows you to swap two values within the `better_float` instance via their indexes.

### better_float fa_del_value(better_float* array, unsigned index);
  This function allows you to delete a value from the `better_float` instance,
  returning a new instance with the value at the given index removed.
  
### void fa_clean_arr(better_float* array);
  If the `better_float` instance has been attained from one of the functions which return a `better_float` instance,
  this function would `free()` the array. It is also used by some other functions.
  
### better_float fa_split_arr(better_float* array, unsigned index, unsigned lor);
  This function allows you to split the array at a given index.
  If `lor` is 0, the values left of the given `index` will be kept,
  and if `lor` is non-0, the values right of the given `index` including the index will be kept.
  
### better_float fa_join_arr(better_float* array_1, better_float* array_2, unsigned lor);
  This function allows you to join two instances of `better_float` together.
  If `lor` is 0, `array_2` will be appended to the left of `array_1`,
  and if `lor` is non-0, `array_2` will be appended to the right of `array_1`.

### better_float fa_trim_arr(better_float* array, unsigned len, unsigned lor);
  This function allows you to trim `len` items on the left or right on the given `array`,
  If `lor` is 0, `array` will be trimmed on the left,
  and if `lor` is non-0, `array` will be trimmed on the right.

### better_float fa_reverse_arr(better_float* array);
  This function allows you to reverse the order items within a `better_float` instance's array.

### better_float fa_expand_arr(better_float* array, unsigned len, float base_value);
  This function allows you to increase the length of the float* array in `array`,
  by `len` items all with a default value of `base_value`.
  
### better_float fa_fit_to_arr(better_float* array, unsigned len, float base_value);
  This function allows you to set the length of the float* array in `array` to `len` items,
  if `len` is greater than the number of items currently in the array, it is resized and the extra items have a default value of `base_value`,
  if `len` is less than the number of items, the array will be cut to `len` items, with the rest discarded.
  if `len` is equal to the number of items, the array will remain the same.

#### better_float fa_return_expand(better_float* array, float* new_array, float base_value, unsigned size, unsigned len);
  This function is used by `fa_expand_arr` and `fa_fit_to_arr`, but cannot be accessed from outside `fa_better.c`.
  The primary use of it is to return a `better_float` instance of which has been edited according to the internal function that called it.

##### better_float fa_expanded_get_arr(float* float_array, unsigned size_param, unsigned length, bool isMalloc, bool shouldFree);
  This function is what `fa_get_array` expands to. This is also used in some other functions to return a `better_float` instance.
