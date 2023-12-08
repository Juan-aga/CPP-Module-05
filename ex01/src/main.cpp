#include "Form.hpp"
#include "Bureaucrat.hpp"

int main( void )
{
    {
        Bureaucrat  a("bureauA", 1);
        Bureaucrat  b("bureauB", 75);
        Bureaucrat  c("bureauC", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << c << std::endl;

        Form        formA("formA", 100, 100);
        Form        formB("formB", 1, 1);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        c.signForm(formA);
        std::cout << formA << std::endl;
        b.signForm(formA);
        std::cout << formA << std::endl;
        a.signForm(formA);
        std::cout << formA << std::endl;
        a.signForm(formB);
        std::cout << formB << std::endl;
    }
    std::cout << "\n\n";
    {
        Bureaucrat  a("bureauA", 1);
        Bureaucrat  b("bureauB", 75);
        Bureaucrat  c("bureauC", 150);

        Form        fA("formA", 100, 100);
        Form        fB("formB", 1, 1);
        Form        fC(fB);
        Form        fD("FormD", 200, -10);

        std::cout << fA << std::endl;
        std::cout << fB << std::endl;
        std::cout << fC << std::endl;
        std::cout << fD << std::endl;

        fD = fA;
        std::cout << fD << std::endl;

        c.signForm(fD);
        std::cout << fD << std::endl;
    }

    return 0;
}