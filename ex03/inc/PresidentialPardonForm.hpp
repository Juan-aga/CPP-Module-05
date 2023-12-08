#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( const std::string & target );
        PresidentialPardonForm( PresidentialPardonForm const & pardon );
        ~PresidentialPardonForm( void );

        PresidentialPardonForm & operator=( PresidentialPardonForm const & pardon );

        void                    execution( void ) const;
};

#endif