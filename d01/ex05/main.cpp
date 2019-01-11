

// # BLUE        =   \033[0;94m
// # YELLOW      =   \033[0;33m
// # LIGHT       =   \033[0;5m
// # COLOR_OFF   =   \033[0m
// # GREEN       =   \033[0;32m
// # PURPLE      =   \033[0;35m
// # CYAN        =   \033[0;36m

// # RED         =   \033[0;31m 


#include "Brain.hpp"
#include "Human.hpp"

int						main(void)
{
  Human					bob;

  std::cout << bob.identify() << std::endl;
  std::cout << bob.getBrain().identify() << std::endl;
}
