#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = "";
}

PresidentialPardonForm::PresidentialPardonForm( const std::string & target ): \
    AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & pardon ): \
    AForm(pardon.getName(), pardon.getSignGrade(), pardon.getExecGrade())
{
    this->_target = pardon._target;   
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{

}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & pardon )
{
    if (this != &pardon)
    {
        this->setSigned(pardon.getIsSigned());
        this->_target = pardon._target;
    }
    return *this;
}

void    PresidentialPardonForm::execution( void ) const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}