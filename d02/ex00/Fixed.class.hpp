

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
