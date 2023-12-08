#include "Bureaucrat.hpp"

int main( void )
{
    Bureaucrat  a("bureau1", 1);
    Bureaucrat  b("bureau2", 75);
    Bureaucrat  c("bureau3", 150);
    Bureaucrat  d(c);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    b.incrementGrade();
    std::cout << b << std::endl;

    a.incrementGrade();
    std::cout << a << std::endl;

    c.decrementGrade();
    std::cout << c << std::endl;

    c.incrementGrade();
    std::cout << c << std::endl;

    std::cout << d << std::endl;
    d = a;
    std::cout << d << std::endl;

    Bureaucrat  f("bureau4", 200);
    std::cout << f << std::endl;

    Bureaucrat  g;
    std::cout << g << std::endl;

    return 0;
}