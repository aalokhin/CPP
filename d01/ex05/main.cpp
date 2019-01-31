#include "Brain.hpp"
#include "Human.hpp"

int						main(void)
{
  Human					bob;

  std::cout << bob.identify() << std::endl;

  std::cout << bob.getBrain().identify() << std::endl;
  
 /* std::cout << "The aforementioned brain belongs to  " << \
  bob.getBrain()._belongs_to << std::endl\
   << "It has the size of " << bob.getBrain()._size << " cells. (Really? so smaaall?)" << std::endl\
   << "And its age is: " << bob.getBrain()._age << "." <<  std::endl; */
  return (0);
}
