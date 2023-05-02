#include "Calculate Total.h"

float tax = 1.06;
int meals = 1000;
int drinks = 500;
int sides = 200;

float calculate_main(float total_num) {
    total_num += (meals * tax) / 100.00f;
    return total_num;
}

float calculate_drinks(int total_num) {
    total_num += (drinks * tax) / 100.00;
    return total_num;
}

float calculate_sides(int total_num) {
    total_num += (sides * tax) / 100.00;
    return total_num;
}