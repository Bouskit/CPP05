#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
    public:
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        
        Form(const std::string& name, int signGrade, int execGrade);

        const std::string& getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getIsSigned() const;

        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class AlreadySignedException : public std::exception {
            public:
                const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif