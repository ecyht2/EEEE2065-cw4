/** @file mandelbrot-set.cpp File containing the implementation of the
 * Mandelbrot class.
 *
 * Copyright [2022] ecyht2
 * */

#include "./mandelbrot-set.h"

#include <fstream>
#include <iostream>

#include "./complex.h"

/** Namespace containing all functions and and classes for this coursework. */
namespace cw4 {
/** Default constructor for Mandelbrot class.
 *
 * The default sets the value of xMin = -2, xStep = 0.02, xMax = 1,
 * yMin = -1, yStep = 0.02, yMax = 1.
 * */
Mandelbrot::Mandelbrot(void) : Mandelbrot(-2, 0.02, 1, -1, 0.02, 1) {}

/** Parameterize constructor for Mandelbrot class.
 *
 * @param xMin The value of xMin.
 * @param xStep The value of xStep.
 * @param xMax The value of xMax.
 * @param yMin The value of yMin.
 * @param yStep The value of yStep.
 * @param yMax The value of yMax.
 * */
Mandelbrot::Mandelbrot(double xMin, double xStep, double xMax, double yMin,
                       double yStep, double yMax)
    : xMin(xMin), xStep(xStep), xMax(xMax), yMin(yMin), yStep(yStep),
      yMax(yMax) {
  // Allocating space for MBS
  this->calcNxNy();
  MBS = new int[Nx * Ny];
  // Calculating MBS
  this->calcMBS();
}

/** Destructor for Mandelbrot class.
 *
 * This is used to deallocate the MBS array.
 * */
Mandelbrot::~Mandelbrot(void) { delete[] MBS; }

//////////
// Setters
/** Sets the range of MBS.
 *
 * @param xMin The value of xMin.
 * @param xStep The value of xStep.
 * @param xMax The value of xMax.
 * @param yMin The value of yMin.
 * @param yStep The value of yStep.
 * @param yMax The value of yMax.
 * */
void Mandelbrot::setRange(double xMin, double xStep, double xMax, double yMin,
                          double yStep, double yMax) {
  // Deleting previous MBS
  delete[] MBS;

  // Setting new real parameters
  this->xMin = xMin;
  this->xStep = xStep;
  this->xMax = xMax;

  // Setting new imaginary parameters
  this->yMin = yMin;
  this->yStep = yStep;
  this->yMax = yMax;

  // Reallocating new MBS
  this->calcNxNy();
  MBS = new int[Nx * Ny];

  // Recalculating MBS
  this->calcMBS();
}

/////////
// Others
/** Prints the range of x, y, Nx and Ny. */
void Mandelbrot::printRange(void) {
  std::cout << "Mandelbrot Set of: "
            << std::endl
            // Real parameters
            << "x: [" << this->xMin << ":" << this->xStep << ":" << this->xMax
            << "], "
            << "Nx: " << this->Nx
            << std::endl
            // Imaginary parameters
            << "y: [" << this->yMin << ":" << this->yStep << ":" << this->yMax
            << "], "
            << "Ny: " << this->Ny << std::endl;
}

/** Prints the Mandelbrot set image. */
void Mandelbrot::printMBS(void) {
  // Looping of the imaginary axis
  for (unsigned int y = 0; y < Ny; y++) {
    // Looping of the real axis
    for (unsigned int x = 0; x < Nx; x++) {
      if (this->MBS[x + y * Nx]) {
        // Printing in set
        std::cout << this->inSet;
      } else {
        // Printing not in set
        std::cout << this->outSet;
      }
    }
    std::cout << std::endl;
  }
}

/** Computes Nx and Ny and set the values accordingly. */
void Mandelbrot::calcNxNy(void) {
  // Resetting Nx and Ny
  this->Nx = 1;
  this->Ny = 1;

  // Calcculating Nx
  for (double x = xMin; x < this->xMax; x += this->xStep) {
    Nx++;
  }
  // Calcculating Ny
  for (double y = yMin; y < this->yMax; y += this->yStep) {
    Ny++;
  }
}

/** Computes the MBS. */
void Mandelbrot::calcMBS(void) {
  // Looping over all imaginary numbers
  for (unsigned int y = 0; y < Ny; y++) {
    // Looping over all real numbers
    for (unsigned int x = 0; x < Nx; x++) {
      // Initial values
      Complex c(this->xMin + x * this->xStep, this->yMax - y * this->yStep);
      bool inSet = true;
      Complex z(0, 0);

      // Performing Check
      for (unsigned int i = 0; i < this->max_iteration; i++) {
        // Applying formula
        z = (z ^ 2) + c;

        // Breaks loop if it diverges
        if (z.abs() > 2) {
          inSet = false;
          break;
        }
      }

      // Setting MBS value
      MBS[x + y * Nx] = inSet;
    }
  }
}

void testMBSClass(void) {
  // Testing default constructor
  Mandelbrot mbs;
  mbs.printRange();

  // Testing setRange()
  mbs.setRange(-1, 0.1, 1, -1, 0.1, 1);
  mbs.printRange();

  // Testing parameterized constructor
  Mandelbrot mbs2(-1, 0.1, 1, -1, 0.1, 1);
  mbs.printRange();
}

void evalMBS(void) {
  Mandelbrot MBS;
  MBS.printRange();
  MBS.printMBS();
}
}  // namespace cw4
