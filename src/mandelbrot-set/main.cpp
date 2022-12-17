#include <iostream>

#include "complex.h"
#include "mandelbrot-set.h"

using namespace std;

int main(int argc, char *argv[]) {
    // cw4::testComplexClass();
    cw4::Mandelbrot MBS;
    MBS.printRange();
    MBS.printMBS();
    return 0;
}
