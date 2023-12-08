#ifndef INTERN_H
# define INTERN_H

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define NUM_FORMS 3

class Intern
{
    private:
        enum    _FORMS {
            PRESIDENTIAL,
            ROBOTOMY,
            SHRUBBERY
        };
        typedef AForm * (*_constructorPtr)(const std::string &);
        typedef struct s_forms
        {
            const char *    name;
            _constructorPtr  constructor;
            int             key;
        }   t_forms;
        t_forms formConstructor[NUM_FORMS];

        static AForm *  makePardon( const std::string & target);
        static AForm *  makeRobot( const std::string & target);
        static AForm *  makeShrubbery( const std::string & target);
        int             makeIndex( const std::string & key );
        
    public:
        Intern( void );
        Intern( Intern const & intern );
        ~Intern( void );

        Intern &    operator=( Intern const & intern );

        AForm *     makeForm( const std::string & form, const std::string & target );

};

#endif