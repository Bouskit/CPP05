#include "AForm.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

AForm::AForm() 
: _name("?"), _isSigned(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

AForm::~AForm() {}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const AForm& af) {
    out << "📄 Form \"" << af.getName() << "\" ["
        << "Sign grade: " << af.getSignGrade() << ", "
        << "Exec grade: " << af.getExecGrade() << ", "
        << "Status: " << (af.getIsSigned() ? "✅ signed" : "❌ unsigned")
        << "]";
    return out;
}


// ───────────────────────────────── GETTERS / SETTERS ─────────────────────────────────

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────

void AForm::beSigned(const Bureaucrat& signor) {
    if (signor.getGrade() > _signGrade) 
        throw GradeTooLowException();
    if (_isSigned)
        throw AlreadySignedException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();

    executeAction();
}

// ───────────────────────────────────── EXCEPTION ─────────────────────────────────────

const char* AForm::GradeTooHighException::what() const throw() {
    return "⛔ Grade too high to sign!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "⛔ Grade too low to sign!";
}

const char* AForm::AlreadySignedException::what() const throw() {
    return "⛔ Form is already signed!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "⛔ Form is not signed, cannot execute it!";
}