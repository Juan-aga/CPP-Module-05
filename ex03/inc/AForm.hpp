#ifndef AFORM_H
# define AFORM_H

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _isSigned;
    const int           _signGrade;
    const int           _execGrade;

public:
    AForm( void );
    AForm( const std::string name, const int signGrade, const int execGrade );
    AForm( AForm const & form );
    virtual ~AForm( void );

    AForm &         operator=( AForm const & form );

    std::string     getName( void ) const;
    bool            getIsSigned( void ) const;
    int             getSignGrade( void ) const;
    int             getExecGrade( void ) const;

    void            setSigned( bool type );

    bool            beSigned( Bureaucrat const & bureauc );
    bool            execute( Bureaucrat const & bureauc ) const;
    virtual void    execution( void ) const = 0;
    
    class           GradeTooHighException;
    class           GradeTooLowException;
    class           NotSignedException;
};

std::ostream &  operator<<( std::ostream & os, const AForm & form);

#endif