#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
    public:
        AForm();
        AForm(const std::string& name, int signGrade, int execGrade);
        virtual ~AForm() {};

        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        const std::string& getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;
        
        void beSigned(const Bureaucrat& signor);
        void execute(const Bureaucrat& executor) const;
        virtual void executeAction() const = 0;

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class AlreadySignedException : public std::exception {
            public: 
                const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public: 
                const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
};

std::ostream& operator<<(std::ostream& out, const AForm& af);

#endif
