#include "ShrubberyCreationForm.hpp"
#include <ctime>
#include <cstdlib>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string & target ): \
    AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & shru ): \
    AForm(shru.getName(), shru.getSignGrade(), shru.getExecGrade())
{
    this->_target = shru._target;   
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & shru )
{
    if (this != &shru)
    {
        this->setSigned(shru.getIsSigned());
        this->_target = shru._target;
    }
    return *this;
}

void    ShrubberyCreationForm::execution( void ) const
{
    int             random;
    std::ofstream   outputFile((this->_target + "_shrubbery").c_str());
    const char *    tree[] =
    {
        "       *      ",
        "      ***     ",
        "     *****    ",
        "    *******   ",
        "   *********  ",
        "  *********** ",
        " *************",
        "      |||     "
    };

    std::srand(std::time(NULL));
    random = std::rand() % 5 + 1;
    if (DEBUG)
        std::cout << "Random number: " << random << std::endl;
    if (outputFile)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < random; j++)
                outputFile << tree[i];
            outputFile << std::endl;
        }
        outputFile << std::endl;
    }
    else
        std::cerr << "Failed to create or open " << this->_target << "_shrubbery.\n";
}