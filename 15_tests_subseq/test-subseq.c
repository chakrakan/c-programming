#include <stdlib.h>
#include <stdio.h>

size_t maxSeq(int * array, size_t n);

int main(void) {
  int test_arr_empty[] = {};
  int test_arr_single_element[] = {1};
  int test_arr_negative_elements[] = {-10, -5, -4, -1, 0};
  int test_arr_same_elements[] = {1, 1, 1, 1, 1};
  int test_arr_two_contiguos_same_length[] = {1, 2, 1, 3, 4, 7, 1, 5, 9, 12};
  int test_arr_decreasing[] = {9, 5, 3, 1};
  int test_sudden_increase[] = {1, 2, 2000};

  
  if (maxSeq(test_sudden_increase, 3) != 3) {
    printf("Failed sudden increase\n");
    return EXIT_FAILURE;
  }
  
  if (maxSeq(test_arr_negative_elements, 5) != 5) {
    printf("Failed negative elements\n");
    return EXIT_FAILURE;
  }


  if (maxSeq(test_arr_same_elements, 5) != 1) {
    printf("Failed same elements\n");
    return EXIT_FAILURE;
  }
  

  if (maxSeq(test_arr_two_contiguos_same_length, 10) != 4) {
    printf("Failed two contiguos same length\n");
    return EXIT_FAILURE;
  }
  
  if (maxSeq(test_arr_empty, 0)) {
    printf("Failed empty array\n");
    return EXIT_FAILURE;
  }

  if (maxSeq(test_arr_single_element, 1) != 1) {
    printf("Failed single element\n");
    return EXIT_FAILURE;
  }

  if (maxSeq(NULL, 0)) {
    printf("Failed NULL array\n");
    return EXIT_FAILURE;
  }

  if (maxSeq(test_arr_decreasing, 4) != 1) {
    printf("Failed decreasing array\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
