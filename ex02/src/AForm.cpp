#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <sstream>

class       AForm::GradeTooHighException: public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "<GradeTooHighException> Grade can't be lower than 1.";
        }
};

class       AForm::GradeTooLowException: public std::exception
{

    public:
        virtual const char * what() const throw()
        {
            return "<GradeTooLowException> Grade can't be greater than 150.";
        }
        virtual const char * what( int grade, std::string type ) const throw()
        {
            std::ostringstream  num;
        
            num << grade;
            _message = "<GradeTooLowException> Grade to " + type + " can't be lower than " + num.str() + ".";
            return _message.c_str();
        }
        virtual ~GradeTooLowException() throw()
        {

        }
    private:
        mutable std::string _message;
};

class       AForm::NotSignedException: public std::exception
{
    public:
        virtual const char * what( std::string name ) const throw()
        {
            _message = "<NotSignedException> The form " + name + " is not signed, can't be executed.";
            return _message.c_str();
        }
        virtual ~NotSignedException() throw()
        {
            
        }
    private:
        mutable std::string _message;

};

AForm::AForm( void ): _name("Unknow form"), _isSigned(false), _signGrade(150), _execGrade(150)
{

}

AForm::AForm( const std::string name, const int signGrade, const int execGrade ):
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

AForm::AForm( AForm const & form):
_name(form._name), _isSigned(form._isSigned), _signGrade(form._signGrade), _execGrade(form._execGrade)
{

}

AForm::~AForm( void )
{

}

AForm &      AForm::operator=( AForm const & form )
{
    if (this != &form)
    {
        if (DEBUG)
            std::cout << "Can't change consts: _name, _signGrade, _execGrade.\n";
        this->_isSigned = form._isSigned;
    }
    return *this;
}

std::string AForm::getName( void ) const
{
    return this->_name;
}

bool        AForm::getIsSigned( void ) const
{
    return this->_isSigned;
}

int         AForm::getSignGrade( void ) const
{
    return this->_signGrade;
}

int         AForm::getExecGrade( void ) const
{
    return this->_execGrade;
}

void        AForm::setSigned( bool type )
{
    this->_isSigned = type;
}

bool       AForm::beSigned( Bureaucrat const & bureauc )
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
        msg = e.what(this->_signGrade, "sign");
        std::cerr << msg << std::endl;
        return false;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

bool            AForm::execute( Bureaucrat const & bureac ) const
{
    try
    {
        if (!this->_isSigned)
            throw NotSignedException();
        else if (bureac.getGrade() > this->_execGrade)
            throw GradeTooLowException();
        else
        {
            this->execution();
            return true;
        }
    }
    catch(GradeTooLowException & e)
    {
        std::cerr << e.what(this->_execGrade, "execute") << std::endl;
        return false;
    }
    catch(NotSignedException & e)
    {
        std::cerr << e.what(this->_name) << std::endl;
        return false;
    }
    catch(const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
    
}

std::ostream &      operator<<( std::ostream & os, const AForm & form)
{
    os << form.getName() << ", sign grade: " << form.getSignGrade() \
    << ", execute grade: " << form.getExecGrade() << ", signed: " \
    << std::boolalpha << form.getIsSigned() << ".";

    return os;
}