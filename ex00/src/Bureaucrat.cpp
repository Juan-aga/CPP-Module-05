#include "Bureaucrat.hpp"

class               Bureaucrat::GradeTooHighException: public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "<GradeTooHighException> Grade can't be lower than 1.";
        }
};

class               Bureaucrat::GradeTooLowException: public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "<GradeTooLowException> Grade can't be greater than 150.";
        }
};

Bureaucrat::Bureaucrat( void ): _name("Anonimus"), _grade(150)
{

}

Bureaucrat::Bureaucrat( const std::string name, int grade ): _name(name)
{
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        else
            this->_grade = grade;
    }
    catch( GradeTooHighException & e )
    {
        std::cerr << e.what() << std::endl;
        this->_grade = 150;
    }
    catch( GradeTooLowException & e )
    {
        std::cerr << e.what() << std::endl;
        this->_grade = 150;
    }
    catch( const std::exception & e )
    {
        std::cerr << e.what() << std::endl;
        this->_grade = 150;
    }
}

Bureaucrat::Bureaucrat( Bureaucrat const & burec ): _name(burec._name), _grade(burec._grade)
{

}

Bureaucrat::~Bureaucrat( void )
{

}

Bureaucrat &    Bureaucrat::operator=( Bureaucrat const & burec )
{
    if (this != &burec)
    {
        if (DEBUG)
            std::cout << "Can't change const _name.\n";
        this->_grade = burec.getGrade();
    }
    return *this;
}

std::string     Bureaucrat::getName( void ) const
{
    return this->_name;
}

int             Bureaucrat::getGrade( void ) const
{
    return this->_grade;
}

void            Bureaucrat::incrementGrade( void )
{
    try
    {
        if (this->_grade == 1 )
            throw GradeTooHighException();
        else
            this->_grade --;
    }
    catch( GradeTooHighException & e )
    {
        std::cerr << e.what() << std::endl;
    }
    catch( const std::exception & e )
    {
        std::cerr << e.what() << std::endl;
    } 
}

void            Bureaucrat::decrementGrade( void )
{
    try
    {
        if (this->_grade == 150)
            throw GradeTooLowException();
        else
            this->_grade++;
    }
    catch( GradeTooLowException & e )
    {
        std::cerr << e.what() << std::endl;
    }
    catch( const std::exception & e )
    {
        std::cerr << e.what() << std::endl;
    }
}

std::ostream &     operator<<( std::ostream & os, const Bureaucrat & burec )
{
    os << burec.getName() << ", bureaucrat grade " << burec.getGrade() << ".";
    return os;
}