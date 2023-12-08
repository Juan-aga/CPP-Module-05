#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( const std::string & target );
        RobotomyRequestForm( RobotomyRequestForm const & robo );
        ~RobotomyRequestForm( void );

        RobotomyRequestForm & operator=( RobotomyRequestForm const & robo );

        void                    execution( void ) const;
};

#endif