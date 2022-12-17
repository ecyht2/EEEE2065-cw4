/** @file File containing the implementation of the Complex class. */

#include "complex.h"

#include <cmath>
#include <iostream>

/** Namespace containing all functions and and classes for this coursework. */
namespace cw4 {
    /** Default constructor for Complex class.
     *
     * It creates a Complex class with both the real and imaginary part
     * set to 0.
     * */
    Complex::Complex(void): Complex(0, 0) {

    }

    /** Parameterized constructor for Complex class.
     *
     * @param real The real part of the complex number.
     * @param imag The imag part of the complex number.
     * @param polar If set to true, it will assume the numbers given is
     * in polar form and treats the real parameter as the magnitude and
     * imag as the phase.
     *
     * @note The phase is assumed to be in radians.
     * */
    Complex::Complex(double real, double imag, bool polar) {
        // If polar is true
        if (polar) {
            double mag = real;
            double phase = imag;

            // Converting to cartesian
            real = mag * cos(phase);
            imag = mag * sin(phase);
        }

        // Setting numbers
        this->setReal(real);
        this->setImag(imag);
    }

    //////////
    // Setters
    /** Sets the real part of the complex number.
     *
     * @param real The number to set the real part to.
     * */
    void Complex::setReal(double real) {
        this->m_real = real;
    }

    /** Sets the imaginary part of the complex number.
     *
     * @param imag The number to set the imaginary part to.
     * */
    void Complex::setImag(double imag) {
        this->m_imag = imag;
    }

    //////////
    // Getters
    /** Gets the real part of the complex number.
     *
     * @return The real part of the complex number.
     * */
    double Complex::getReal(void) const {
        return this->m_real;
    }

    /** Gets the imaginary part of the complex number.
     *
     * @return The imaginary part of the complex number.
     * */
    double Complex::getImag(void) const {
        return this->m_imag;
    }

    /** Gets the magnitude (absolute value) of the complex number.
     *
     * @return The magnitude of the complex number.
     * */
    double Complex::abs(void) const {
        return sqrt(this->getReal() * this->getReal() +
                    this->getImag() * this->getImag());
    }

    /** Gets the phase of the complex number.
     *
     * @return The phase of the complex number.
     *
     * @note The phase is in radians.
     * */
    double Complex::phase(void) const {
        return atan(this->getImag() / this->getReal());
    }

    /** Gets the conjugate of the complex number.
     *
     * @return The conjugate of the complex number.
     * */
    Complex Complex::conjugate(void) const {
        return Complex(this->getReal(), -this->getImag());
    }

    ////////////
    // Operators
    /** Adds the complex number with another.
     *
     * @param other The other Complex number to add with.
     * */
    void Complex::add(Complex other) {
        this->setReal(this->getReal() + other.getReal());
        this->setImag(this->getImag() + other.getImag());
    }

    /** Subtracts the complex number with another.
     *
     * @param other The other Complex number to subtract with.
     * */
    void Complex::sub(Complex other) {
        this->setReal(this->getReal() - other.getReal());
        this->setImag(this->getImag() - other.getImag());
    }

    /** Multiplies the complex number with another.
     *
     * @param other The other Complex number to multiply with.
     * */
    void Complex::mult(Complex other) {
        // Calculating new real and imaginary parts
        double new_real = this->getReal() * other.getReal() -
            this->getImag() * other.getImag();
        double new_imag = this->getReal() * other.getImag() +
            this->getImag() * other.getReal();

        // Setting new real and imag
        this->setReal(new_real);
        this->setImag(new_imag);
    }

    /** Divides the complex number with another.
     *
     * @param other The other Complex number to divides with.
     * */
    void Complex::div(Complex other) {
        other.inv();
        this->mult(other);
    }

    /** Inverts the complex number. */
    void Complex::inv(void) {
        double denominator = this->getReal() * this->getReal() +
            this->getImag() * this->getImag();

        this->setImag(-this->getImag());

        // Dividing by denominator
        this->setReal(this->getReal() / denominator);
        this->setImag(this->getImag() / denominator);
    }

    /** Squares the complex number. */
    void Complex::square(void) {
        this->mult(*this);
    }

    ///////////////////////
    // Overloaded Operators
    /** Performs addition on two complex number.
     *
     * @param c The other complex number to add with.
     * @return The sum of both complex numbers.
     * */
    Complex Complex::operator + (Complex c) {
        c.add(*this);
        return c;
    }

    /** Performs subtraction on two complex number.
     *
     * @param c The other complex number to subtract with.
     * @return The difference of both complex numbers.
     * */
    Complex Complex::operator - (Complex c) {
        Complex ret(*this);
        ret.sub(c);
        return ret;
    }

    /** Performs multiplication on two complex number.
     *
     * @param c The other complex number to multiply with.
     * @return The product of both complex numbers.
     * */
    Complex Complex::operator * (Complex c) {
        c.mult(*this);
        return c;
    }

    /** Performs division on two complex number.
     *
     * @param c The other complex number to divide with.
     * @return The quotient of both complex numbers.
     * */
    Complex Complex::operator / (Complex c) {
        c.inv();
        c.mult(*this);
        return c;
    }

    /** Raise the complex to the power of n.
     *
     * @param n The power to raise to
     * @return The result of the exponent.
     * */
    Complex Complex::operator ^ (int n) {
        Complex ret(*this);

        // If n is 0 return 1 + 0j
        if (n == 0) {
            ret.setReal(1);
            ret.setImag(0);
            return ret;
        }

        // Raising to the power of n
        for (int i = 0; i < std::abs(n - 1); i++) {
            if (n > 0) {
                ret.mult(*this);
            } else {
                ret.div(*this);
            }
        }

        return ret;
    }

    /** Prints the complex number into an output stream.
     *
     * @param out The output stream to print to
     * @param self The Complex class to print.
     * @return The new output stream with the class printed.
     * */
    std::ostream& operator << (std::ostream &out, const Complex &self) {
        out << self.getReal() << " + " << self.getImag() << "j";
        return out;
    }

    /////////
    // Others
    /** Prints the complex number. */
    void Complex::print(void) {
        std::cout << *this << std::endl;
    }

    /** Prints the complex number with a label.
     *
     * @param label The label of the complex number.
     */
    void Complex::print(std::string label) {
        std::cout << label << ": ";
        this->print();
    }

    /** Function to test methods of Complex class. */
    void testComplexClass(void) {
        cw4::Complex c1;
        cw4::Complex c2(69, 420);
        cw4::Complex c3(420, 69);

        // Testing prints
        c1.print();
        c2.print("c2");

        // Testing setters
        c1.setReal(6);
        c1.setImag(9);

        // Testing getters
        std::cout << "New c1: " << c1.getReal() << " + j" << c1.getImag() << std::endl;
        std::cout << "In Polar: (" << c1.abs() << ", " << c1.phase() << ")" << std::endl;
        std::cout << "Conjugate: "; c1.conjugate().print();

        // Testing operators
        c1.add(c2);
        c1.print("c1 + c2");
        c1.sub(c2);
        c1.print("c1 - c2");
        c1.mult(c2);
        c1.print("c1 * c2");
        c1.div(c2);
        c1.print("c1 / c2");
        c1.inv();
        c1.print("1 / c1");
        c1.square();
        c1.print("c1 * c1");

        // Testing overloaded operators
        std::cout << "c2 + c3: " << c2 + c3 << std::endl;
        std::cout << "c2 - c3: " << c2 - c3 << std::endl;
        std::cout << "c2 * c3: " << c2 * c3 << std::endl;
        std::cout << "c2 / c3: " << c2 / c3 << std::endl;
        std::cout << "c2^2: " << (c2^2) << std::endl;
        std::cout << "c2^-2: " << (c2^-2) << std::endl;
        std::cout << "c2^0: " << (c2^0) << std::endl;
    }
}
