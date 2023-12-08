#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = "";
}

RobotomyRequestForm::RobotomyRequestForm( const std::string & target ): \
    AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & robo ): \
    AForm(robo.getName(), robo.getSignGrade(), robo.getExecGrade())
{
    this->_target = robo._target;   
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{

}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & robo )
{
    if (this != &robo)
    {
        this->setSigned(robo.getIsSigned());
        this->_target = robo._target;
    }
    return *this;
}

void    RobotomyRequestForm::execution( void ) const
{
    int random;
    int noise;

    std::srand(std::time(NULL));
    random = std::rand();
    noise = (random % 7) + 1;
    for (int i = 0; i < noise; i++)
        std::cout << "Drilling noise...\n";
    if (DEBUG)
        std::cout << "Random number: " << random << std::endl;
    if (random % 2)
        std::cout << this->_target << " has been robotomized successfully.\n";
    else
        std::cout << this->_target << " robotomy failed." << std::endl;

}