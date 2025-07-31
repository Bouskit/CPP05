#include "Form.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Form::Form() : _name("Unknown"), _isSigned(false), _signGrade(1), _execGrade(1) {}

Form::Form(const std::string& name, int signGrade, int execGrade) 
: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) 
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) 
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Form::~Form() {
    std::cout << "🧹 Destruction de " << _name << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << "[📝" << f.getName() << "]"
    << (f.getIsSigned() ? " is signed" : " is not signed")
    << " (min to sign : " << f.getSignGrade()
    << " | min to exec : " << f.getExecGrade() << ")."
    << std::endl;
    return out;
}

// ───────────────────────────────── GETTERS / SETTERS ─────────────────────────────────

const std::string& Form::getName() const {
    return _name;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}
bool Form::getIsSigned() const {
    return _isSigned;
}

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _signGrade) 
        throw GradeTooLowException();
    if (_isSigned)
        throw AlreadySignedException();
    _isSigned = true;
}

// ───────────────────────────────────── EXCEPTIONS ─────────────────────────────────────

const char* Form::GradeTooHighException::what() const throw() {
    return "⛔ Grade too high to sign!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "⛔ Grade too low to sign!";
}

const char* Form::AlreadySignedException::what() const throw() {
    return "⛔ Form is already signed!";
}