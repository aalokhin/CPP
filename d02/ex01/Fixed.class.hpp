

#ifndef FIXED_CLASS_HPP
#define FIXED_CLASS_HPP

#include <cmath>

class Fixed
{
  private:
    int _raw;
    static const int _fraction = 8;

  public:
    Fixed();
    Fixed(Fixed const &copy);

    Fixed(const int val_to_convert);
    Fixed(const float val_to_convert);
    ~Fixed();

    Fixed &operator=(Fixed const & over);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat( void ) const;
    int toInt( void ) const; 
};

std::ostream & operator<<(std::ostream &o, Fixed const &over);


#endif
