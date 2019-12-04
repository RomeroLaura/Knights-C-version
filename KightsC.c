
#include <stdio.h>


struct pair_int_int {
    int first;
    int second;
};

pair_int_int make_pair(conts int & a, const int & b){

  struct pair_int_int apair;

  apair.first = a;
  apair.second = b;

  return apair;

}

pair_int_int operator+(const pair_int_int & a, const pair_int_int & b){

  return make_pair(a.first + b.first, a.second + b.second);

}
