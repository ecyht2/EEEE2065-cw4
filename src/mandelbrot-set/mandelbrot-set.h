#ifndef MANDELBROT_SET_H_
#define MANDELBROT_SET_H_

/** @file mandelbrot-set.h File containing declarations related to the
 * Mandelbrot class. */


/** Namespace containing all functions and and classes for this coursework. */
namespace cw4 {
    /** A class that computes the Mandelbrot set (MBS). */
    class Mandelbrot {
        public:
            /** Default constructor for Mandelbrot class.
             *
             * The default sets the value of xMin = -2, xStep = 0.02, yMax = 1,
             * yMin = -1, yStep = 0.02, yMax = 1.
             * */
            Mandelbrot(void);
            /** Parameterize constructor for Mandelbrot class.
             *
             * @param xMin The value of xMin.
             * @param xStep The value of xStep.
             * @param xMax The value of xMax.
             * @param yMin The value of yMin.
             * @param yStep The value of yStep.
             * @param yMax The value of yMax.
             * */
            Mandelbrot(double xMin, double xStep, double xMax,
                       double yMin, double yStep, double yMax);
            /** Destructor for Mandelbrot class.
             *
             * This is used to deallocate the MBS array.
             * */
            ~Mandelbrot(void);

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
            void setRange(double xMin, double xStep, double xMax,
                          double yMin, double yStep, double yMax);

            /////////
            // Others
            /** Prints the range of x, y, Nx and Ny. */
            void printRange(void);
            /** Prints the Mandelbrot set image. */
            void printMBS(void);
        protected:
            /** Computes Nx and Ny and set the values accordingly. */
            void calcNxNy(void);
            /** Computes the MBS. */
            void calcMBS(void);
        private:
            double xMin, /**<The minimum the real axis can be. */
                xStep, /**<The amount each tick on the real axis increases. */
                xMax; /**<The maximum the real axis can be. */

            double yMin, /**<The minimum the imaginary axis can be. */
                yStep, /**<The amount each tick on the imaginary axis
                        * increases. */
                yMax; /**<The maximum the imaginary axis can be. */

            unsigned int Nx = 1, /**<The number of real elements in MBS. */
                Ny = 1; /**<The number of imaginary elements in MBS. */

            int *MBS; /**<Array repesenting the 2D MBS. */

            unsigned int max_iteration = 1000; /**<Maximum iterations to
                                                * determine if the complex
                                                * number is in the set. */

            char inSet = '1', /**<The character to display if the number is in
                               * the MBS. */
                outSet = '0'; /**<The character to display if the number is not
                               * in the MBS. */
    };
}

#endif // MANDELBROT_SET_H_
