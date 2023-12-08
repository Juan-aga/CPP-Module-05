#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <sstream>

class       Form::GradeTooHighException: public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "<GradeTooHighException> Grade can't be lower than 1.";
        }
};

class       Form::GradeTooLowException: public std::exception
{

    public:
        virtual const char * what() const throw()
        {
            return "<GradeTooLowException> Grade can't be greater than 150.";
        }
        virtual const char * what( int grade ) const throw()
        {
            std::ostringstream  num;
        
            num << grade;
            _message = "<GradeTooLowException> Grade to sign can't be lower than " + num.str() + ".";
            return _message.c_str();
        }
        virtual ~GradeTooLowException() throw()
        {

        }
    private:
        mutable std::string _message;
};

Form::Form( void ): _name("Unknow form"), _isSigned(false), _signGrade(150), _execGrade(150)
{

}

Form::Form( const std::string name, const int signGrade, const int execGrade ):
_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    try
    {
        if (signGrade < 1 || execGrade < 1)
            throw GradeTooHighException();
        if (signGrade > 150 || execGrade > 150)
            throw GradeTooLowException();
    }
    catch(GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Form::Form( Form const & form):
_name(form._name), _isSigned(form._isSigned), _signGrade(form._signGrade), _execGrade(form._execGrade)
{

}

Form::~Form( void )
{

}

Form &      Form::operator=( Form const & form )
{
    if (this != &form)
    {
        if (DEBUG)
            std::cout << "Can't change consts: _name, _signGrade, _execGrade.\n";
        this->_isSigned = form._isSigned;
    }
    return *this;
}

std::string Form::getName( void ) const
{
    return this->_name;
}

bool        Form::getIsSigned( void ) const
{
    return this->_isSigned;
}

int         Form::getSignGrade( void ) const
{
    return this->_signGrade;
}

int         Form::getExecGrade( void ) const
{
    return this->_execGrade;
}

bool       Form::beSigned( Bureaucrat const & bureauc )
{
    try
    {
        if (bureauc.getGrade() > this->_signGrade)
            throw GradeTooLowException();
        else if (this->_signGrade < 1 || this->_signGrade > 150 \
            || this->_execGrade < 1 || this->_execGrade > 150)
        {
            if (DEBUG)
                std::cout << "Bad grade in form " << this->_name << ", Can't be signed.\n";
            return false;
        }
        else
        {
            this->_isSigned = true;
            return true;
        }
    }
    catch(GradeTooLowException & e)
    {
        const char *  msg;
        msg = e.what(this->_signGrade);
        std::cerr << msg << std::endl;
        return false;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

std::ostream &      operator<<( std::ostream & os, const Form & form)
{
    os << form.getName() << ", sign grade: " << form.getSignGrade() \
    << ", execute grade: " << form.getExecGrade() << ", signed: " \
    << std::boolalpha << form.getIsSigned() << ".";

    return os;
}