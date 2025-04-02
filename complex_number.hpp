#pragma once

template<typename F> requires std::floating_point<F>
class complex
{
	/* Private members */
	F real_p, imm_p;

public:
	/* Default constructor */
	complex()
		: real_p(0), imm_p(0)
	{}
	
	/* User defined constructor that takes in a floating point
	 * and considers it as the real part of a complex number 
	 * with imaginary part 0
	 */ 
	explicit complex(F real)
		: real_p(real), imm_p(0)
	{}
	
	/* User defined constructor that takes in real part and 
	 * imaginary part
	 */
	complex(F real, F imm)
		: real_p(real), imm_p(imm)
	{}
	
	/* Return the real part */
	
	F Re(void) const {
		return real_p;
	}
	
	/* Return the imaginary part */
	
	F Im(void) const {
		return imm_p;
	}

	/* Return the complex conjugate */
	
	complex<F> conj() const {
	return complex<F>(real_p, -imm_p);
	}
	
	/* Define the += operator between complex numbers */
	complex<F>& operator+=(const complex<F>& other) {
		F a = real_p;
		F b = imm_p;
		F c = other.real_p;
		F d = other.imm_p;
		real_p = a + c;
		imm_p = b + d;
		return *this;
	}
	
	/* Define the + operator in terms of operator +=. */
	complex<F> operator+(const complex<F>& other) const {
		complex<F> sum = *this;
		sum += other;
		return sum;
	}
	
	/* Define the += operator between a complex on the left
     * and an F on the right.*/
    complex<F>& operator+=(const F& other) {
	    F a = real_p;
		F b = imm_p;
		real_p = a + other;
		return *this;
    }
    
    /* Define the + operator between a complex on the left
     * and an F on the right.*/
    complex<F> operator+(const F& other) {
	    complex<F> sum = *this;
		sum += other;
		return sum;
    }
    
    /* Define the unary - operator to compute the opposite */
    complex<F> operator-() const {
	    return complex<F>(-real_p, -imm_p);
    }
    
    /* Define *= operator between complex numbers */
    complex<F>& operator*=(const complex<F>& other) {
		F a = real_p;
		F b = imm_p;
		F c = other.real_p;
		F d = other.imm_p;
		real_p = a*c - b*d;
		imm_p = a*d + b*c;
		return *this;
	}
	
	/* Define the * operator in terms of operator *= */
	complex<F> operator*(const complex<F>& other) const {
		complex<F> prod = *this;
		prod *= other;
		return prod;
	}
	
	/* Define the *= operator between a complex on the left
     * and an F on the right.*/
    complex<F>& operator*=(const F& other) {
	    F a = real_p;
		F b = imm_p;
		real_p = a*other;
		imm_p = b*other;
		return *this;
    }
    
    /* Define the * operator between a complex on the left
     * and an F on the right.*/
    complex<F> operator*(const F& other) {
	    complex<F> sum = *this;
		sum *= other;
		return sum;
    }
    
    
};


/* Define the + operator between an F on the left
 * and a complex number on the right.*/
template<typename F>
complex<F> operator+(const F& f, const complex<F>& c) {
    return complex<F>(c.Re() + f, c.Im()); 
}

/* Define the += operator between an F on the left
 * and a complex number on the right.*/
template<typename F>
complex<F>
operator+=(const F& f, complex<F>& c)
{
    return c += f;
}


/* Define the * operator between an F on the left
 * and a complex number on the right.*/
template<typename F>
complex<F> operator*(const F& f, const complex<F>& c) {
    return complex<F>(c.Re() * f, c.Im() * f);
}

/* Define the *= operator between an F on the left
 * and a complex number on the right.*/
template<typename F>
complex<F>
operator*=(const F& f, complex<F>& c)
{
    return c *= f;
}

/* Overload of << to make complex numbers printable.*/
template<typename F>
std::ostream&
operator<<(std::ostream& os, const complex<F>& c) {
    os << c.Re() << std::showpos << c.Im() << "i";
    return os;
}