#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main( void )
{
    {
        Bureaucrat  a("bureauA", 1);
        Bureaucrat  b("bureauB", 72);
        Bureaucrat  c("bureauC", 150);

        Intern inter;
        std::cout << "\n\n";

        AForm * test =inter.makeForm("presidential pardon", "bender");
        if (test)
        {
            std::cout << *test << std::endl;
            a.executeForm(*test);
            a.signForm(*test);
            a.executeForm(*test);
            delete test;
        }

        std::cout << "\n\n";
        test =inter.makeForm("robotomy request", "bender");
        if (test)
        {
            std::cout << *test << std::endl;
            a.executeForm(*test);
            a.signForm(*test);
            a.executeForm(*test);
            delete test;
        }

        std::cout << "\n\n";
        test =inter.makeForm("shrubbery creation", "bender");
        if (test)
        {
            std::cout << *test << std::endl;
            a.executeForm(*test);
            a.signForm(*test);
            a.executeForm(*test);
            delete test;
        }

        std::cout << "\n\n";
        test =inter.makeForm("Presidential Pardon", "bender");
        if (test)
        {
            std::cout << *test << std::endl;
            a.executeForm(*test);
            a.signForm(*test);
            a.executeForm(*test);
            delete test;
        }
    }

    return 0;
}