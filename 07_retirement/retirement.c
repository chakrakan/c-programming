#include <stdlib.h>
#include <stdio.h>
double get_balance(double get_balance, double rate);

// declare a struct _retire_info
struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
}
// use typedef to make retire_info
typedef struct _retire_info retire_info;

// retirement function
void retirement(int startAge, double initial, retire_info working,
		retire_info retired) {
  // first, compute retirement account balance each month (working)
  // calculate acc balance increase from returns
  for (int i = 0; i < working.months; i++) {
     printf("Age %3d month %2d you have $%.2lf\n", (startAge / 12), (startAge % 12), initial); 
     initial = get_balance(initial, working.rate_of_return) + working.contribution;
    startAge++;
  }

  for (int i = 0; i < retired.months; i++) {
      printf("Age %3d month %2d you have $%.2lf\n",(startAge/12),(startAge%12),initial);
      initial = get_balance(initial, retired.rate_of_return) + retired.contribution;
      startAge++;
    }  
}

// abstract out get balance function
double get_balance(double balance, double rate_of_return) {
  return balance * (1 + rate_of_return / 12);
}

// main function
int main(void) {
  retire_info working = { 489, 1000, 0.045 };
  retire_info retired = { 384, -4000, 0.01 };
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
