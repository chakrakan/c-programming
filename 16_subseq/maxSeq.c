#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n) {
  if (n <= 0 || array == NULL) {
    return NULL;
  }
  if (n == 1) {
    return 1;
  }
  size_t max_seq = 1, temp_seq = 1;
  for (size_t i = 0; i < n-1;i++) {
    if (array[i] >= array[i+1]) {
      temp_seq = 1;
    } else {
      /* reset */
      temp_seq++;
    }    
    if (temp_seq > max_seq) {
      max_seq = temp_seq;
    }
  }
  return max_seq;
}
      
