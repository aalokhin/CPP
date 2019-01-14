

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

class Fixed
{
  private:
    int _raw;
    static const int _fraction = 8;
  public:
    Fixed();
    Fixed(Fixed const &copy);
    ~Fixed();

    Fixed &operator=(Fixed const & over);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif


/*
• Private members :
◦ An integer to store the fixed point value.
◦ A static constant integer to store the number of fractional bits. This con- stant will always be the litteral 8.
• Public members :
◦ A default constructor that initializes the fixed point value to 0.
◦ A destructor.
◦ A copy constructor.
◦ An assignation operator overload.
◦ A member function int getRawBits( void ) const; that returns the raw value of the fixed point value.
◦ A member function void setRawBits( int const raw ); that sets the raw value of the fixed point value.

*/



/*
Default constructor called
Copy constructor called
Assignation operator called   // <-- This line may be missing depending of your implementation
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
Destructor called
Destructor called
Destructor called
*/

/*
Default constructor called
Copy constructor called
Assignation operator called
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
/*