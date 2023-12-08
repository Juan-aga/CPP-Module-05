#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( const std::string & target );
        ShrubberyCreationForm( ShrubberyCreationForm const & shru );
        ~ShrubberyCreationForm( void );

        ShrubberyCreationForm & operator=( ShrubberyCreationForm const & shru );

        void                    execution( void ) const;
};

#endif