#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& name);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    private:
        
};

#endif
