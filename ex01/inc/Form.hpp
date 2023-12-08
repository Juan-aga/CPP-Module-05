#ifndef FORM_H
# define FORM_H

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _execGrade;

public:
    Form( void );
    Form( const std::string name, const int signGrade, const int execGrade );
    Form( Form const & form );
    ~Form( void );

    Form &      operator=( Form const & form );

    std::string getName( void ) const;
    bool        getIsSigned( void ) const;
    int         getSignGrade( void ) const;
    int         getExecGrade( void ) const;

    bool        beSigned( Bureaucrat const & bureauc );
    
    class       GradeTooHighException;
    class       GradeTooLowException;
};

std::ostream &  operator<<( std::ostream & os, const Form & form);

#endif