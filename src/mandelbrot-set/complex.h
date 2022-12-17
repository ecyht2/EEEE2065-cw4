#ifndef COMPLEX_H_
#define COMPLEX_H_

/** @file This file contains declaration related to the Complex class. */

#include <ostream>
#include <string>

namespace cw4 {
    /** A class representing a complex number. */
    class Complex {
        public:
            /** Default constructor for Complex class.
             *
             * It creates a Complex class with both the real and imaginary part
             * set to 0.
             * */
            Complex();
            /** Parameterized constructor for Complex class.
             *
             * @param real The real part of the complex number.
             * @param imag The imag part of the complex number.
             * @param polar If set to true, it will assume the numbers given is
             * in polar form and treats the real parameter as the magnitude and
             * imag as the phase.
             * */
            Complex(double real, double imag, bool polar = false);

            //////////
            // Setters
            /** Sets the real part of the complex number.
             *
             * @param real The number to set the real part to.
             * */
            void setReal(double real);
            /** Sets the imaginary part of the complex number.
             *
             * @param imag The number to set the imaginary part to.
             * */
            void setImag(double imag);

            //////////
            // Getters
            /** Gets the real part of the complex number.
             *
             * @return The real part of the complex number.
             * */
            double getReal(void) const;
            /** Gets the imaginary part of the complex number.
             *
             * @return The imaginary part of the complex number.
             * */
            double getImag(void) const;
            /** Gets the magnitude (absolute value) of the complex number.
             *
             * @return The magnitude of the complex number.
             * */
            double abs(void) const;
            /** Gets the phase of the complex number.
             *
             * @return The phase of the complex number.
             *
             * @note The phase is in radians.
             * */
            double phase(void) const;
            /** Gets the conjugate of the complex number.
             *
             * @return The conjugate of the complex number.
             * */
            Complex conjugate(void) const;

            ////////////
            // Operators
            /** Adds the complex number with another.
             *
             * @param other The other Complex number to add with.
             * */
            void add(Complex other);
            /** Subtracts the complex number with another.
             *
             * @param other The other Complex number to subtract with.
             * */
            void sub(Complex other);
            /** Multiplies the complex number with another.
             *
             * @param other The other Complex number to multiply with.
             * */
            void mult(Complex other);
            /** Divides the complex number with another.
             *
             * @param other The other Complex number to divides with.
             * */
            void div(Complex other);
            /** Inverts the complex number. */
            void inv(void);
            /** Squares the complex number. */
            void square(void);

            ///////////////////////
            // Overloaded Operators
            /** Performs addition on two complex number.
             *
             * @param c The other complex number to add with.
             * @return The sum of both complex numbers.
             * */
            Complex operator + (Complex c);
            /** Performs subtraction on two complex number.
             *
             * @param c The other complex number to subtract with.
             * @return The difference of both complex numbers.
             * */
            Complex operator - (Complex c);
            /** Performs multiplication on two complex number.
             *
             * @param c The other complex number to multiply with.
             * @return The product of both complex numbers.
             * */
            Complex operator * (Complex c);
            /** Performs division on two complex number.
             *
             * @param c The other complex number to divide with.
             * @return The quotient of both complex numbers.
             * */
            Complex operator / (Complex c);
            /** Raise the complex to the power of n.
             *
             * @param n The power to raise to
             * @return The result of the exponent.
             * */
            Complex operator ^ (int n);
            /** Prints the complex number into an output stream.
             *
             * @param out The output stream to print to
             * @param self The Complex class to print.
             * @return The new output stream with the class printed.
             * */
            friend std::ostream& operator << (std::ostream &out,
                                              const Complex &self);

            /////////
            // Others
            /** Prints the complex number. */
            void print(void);
            /** Prints the complex number with a label.
             *
             * @param label The label of the complex number.
             */
            void print(std::string label);
        private:
            double m_real = 0.0; /**<Real part of the complex number. */
            double m_imag = 0.0; /**<Imaginary part of the complex number. */
    };

    /** Function to test methods of Complex class. */
    void testComplexClass(void);
}


#endif // COMPLEX_H_
