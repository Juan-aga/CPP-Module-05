#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main( void )
{
    {
        Bureaucrat  a("bureauA", 1);
        Bureaucrat  b("bureauB", 72);
        Bureaucrat  c("bureauC", 150);

        ShrubberyCreationForm       fS("Shrubbery");
        RobotomyRequestForm         fR("Robotomy");
        PresidentialPardonForm      fP("Pardon");

        std::cout << fS << std::endl;
        std::cout << fR << std::endl;
        std::cout << fP << std::endl;

        std::cout << "\n\n";

        b.executeForm(fS);
        b.signForm(fS);
        std::cout << fS << std::endl;
        b.executeForm(fS);

        std::cout << "\n\n";

        std::cout << fR << std::endl;
        b.executeForm(fR);
        b.signForm(fR);
        std::cout << fR << std::endl;
        b.executeForm(fR);
        a.signForm(fR);
        std::cout << fR << std::endl;
        a.executeForm(fR);

        std::cout << "\n\n";

        std::cout << fP << std::endl;
        b.executeForm(fP);
        b.signForm(fP);
        std::cout << fP << std::endl;
        b.executeForm(fP);
        a.signForm(fP);
        std::cout << fP << std::endl;
        a.executeForm(fP);


    }

    return 0;
}