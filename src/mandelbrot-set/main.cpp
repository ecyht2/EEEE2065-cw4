/** @file main.cpp Main file containing the main function to calculates
 * and prints a Mandelbrot set plot.
 * */

#include <iostream>

#include "complex.h"
#include "mandelbrot-set.h"

using namespace std;

/** The main function to print a Mandelbrot set plot.
 *
 * @param argc The number of arguments passed in.
 * @param argv The arguments passed in.
 * @return The exit status.
 * */
int main(int argc, char *argv[]) {
    // cw4::testComplexClass();
    cw4::Mandelbrot MBS;
    MBS.printRange();
    MBS.printMBS();
    return 0;
}
