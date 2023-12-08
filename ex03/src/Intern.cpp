#include "Intern.hpp"

Intern::Intern( void )
{
    formConstructor[PRESIDENTIAL].name = "presidential pardon";
    formConstructor[PRESIDENTIAL].constructor = &makePardon;
    formConstructor[ROBOTOMY].name = "robotomy request";
    formConstructor[ROBOTOMY].constructor = &makeRobot;
    formConstructor[SHRUBBERY].name = "shrubbery creation";
    formConstructor[SHRUBBERY].constructor = &makeShrubbery;
    for (int i = 0; i < NUM_FORMS; i++)
    {
        formConstructor[i].key = makeIndex(formConstructor[i].name);
        if (DEBUG)
            std::cout << formConstructor[i].name <<" key is: " << formConstructor[i].key << std::endl;
    }
}

Intern::Intern( Intern const & intern )
{
    (void) intern;
}

Intern::~Intern( void )
{

}

Intern &    Intern::operator=( Intern const & intern )
{
    (void) intern;
    return *this;
}

AForm *     Intern::makeForm( const std::string & form, const std::string & target )
{
    int key;

    key = makeIndex(form);
    if (DEBUG)
        std::cout << "Form: " << form << " key is: " << key << std::endl;
    if (formConstructor[key].name && form == formConstructor[key].name)
    {
        std::cout << "Intern creates " << form << std::endl;
        return this->formConstructor[key].constructor(target);
    }
    else
        std::cout << "Intern say that form <" << form << "> doesn’t exist.\n";
    return NULL;
}

AForm *  Intern::makePardon( const std::string & target )
{
    return new PresidentialPardonForm(target);
}

AForm * Intern::makeRobot( const std::string & target )
{
    return new RobotomyRequestForm(target);
}

AForm * Intern::makeShrubbery( const std::string & target )
{
    return new ShrubberyCreationForm(target);
}

int     Intern::makeIndex( const std::string & key )
{
    int value;

    value = 0;
    for (size_t i = 0; i < NUM_FORMS + 1; i++)
        value += static_cast<int>(key[i]) - 1;
    return (value) % NUM_FORMS;
}