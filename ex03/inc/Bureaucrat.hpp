#ifndef BUREUCRAT_H
# define BUREUCRAT_H

# include <iostream>

# include "AForm.hpp"

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

public:
    Bureaucrat( void );
    Bureaucrat( const std::string name, int grade );
    Bureaucrat( Bureaucrat const & burec );
    ~Bureaucrat( void );

    Bureaucrat &    operator=( Bureaucrat const & burec );

    std::string     getName( void ) const;
    int             getGrade( void ) const;
    void            incrementGrade( void );
    void            decrementGrade( void );

    void            signForm( AForm & form ) const;
    void            executeForm( AForm const & form );

    class           GradeTooHighException;
    class           GradeTooLowException;
};

std::ostream &     operator<<( std::ostream & os, const Bureaucrat & burec);

#endif