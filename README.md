# cfloat-better
A simple attempt at making arrays a little easier to work with in C. 

## MACROS

### fa_get_array(float_array)
  This macro should be used to get a "better_float" instance, of which is derived from a structure.
  The instance will contain the array, the length of the array, and the `sizeof(array)`.

### ERROR_FAILED(arg1)
  This macro would be called internally if something were to have gone wrong, 
  printing an error message to stderr and calling `exit()`.

### N_ITEMS(x)
  This macro detemines the number of items within a given array.


## BETTER_FLOAT MEMBERS:

### float* array;
  This is where the float array is stored.
  
### unsigned int type;
  This would contain the `sizeof(array)` value;
  
### unsigned int len : 24;
  This would contain the length of the array member, 
  and is a bitfield of 24 bits to allow the structure to be 16 bytes in size, and not 24 bytes.

### bool isMalloc;
  This would contain either `true` or `false`, and is used to determine if the instance was created directly, or internally malloc'd. This is needed to avoid most memory leaks.


## FUNCTIONS:

### void fa_set_value(better_float* array, unsigned index, float value);
  This function allows you to set an individual value within the better_float instance.
  
### float fa_get_value(better_float* array, unsigned index);
  This function allows you to retrieve an individual value from the better_float instance.
  
### better_float fa_del_value(better_float* array, unsigned index);
  This function allows you to delete a value from the better_float instance,
  returning a new instance with the value at the given index removed.
  
### void fa_clean_arr(better_float* array);
  If the better_float instance has been attained from one of the functions which return a better_float instance,
  this function would `free()` the array.
  
### better_float fa_split_arr(better_float* array, unsigned index, unsigned lor);
  This function allows you to split the array at a given index.
  If `lor` is 0, the values left of the given index will be kept,
  and if `lor` is non-0, the values right of the given index including the index will be kept.
  
### better_float fa_join_arr(better_float* array_1, better_float* array_2, unsigned lor);
  This function allows you to join two instances of better_float together.
  If `lor` is 0, array_2 will be appended to the left of array_1,
  and if `lor` is non-0, array_2 will be appended to the right of array_1.

### better_float fa_trim_arr(better_float* array, unsigned len, unsigned lor);
  This function allows you to trim `len` items on the left or right on the given array,
  If `lor` is 0, array will be trimmed on the left,
  and if `lor` is non-0, array will be trimmed on the right.

#### better_float fa_expanded_get_arr(float* float_array, unsigned size_param, unsigned length, bool isMalloc);
  This function is what `fa_get_array` expands to. This is also used in some other functions to return a better_float instance.
