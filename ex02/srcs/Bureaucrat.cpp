#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

Bureaucrat::Bureaucrat() : _name("?"), _grade(75) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    _grade = other._grade;
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

Bureaucrat::~Bureaucrat() {
    std::cout << "🧹 Destruction de " << _name << std::endl;
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
    _grade = other._grade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << "💼 " << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}

// ───────────────────────────────── GETTERS / SETTERS ─────────────────────────────────

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm& form) const {
    try {
        form.beSigned(*this);
        std::cout << "✅ " << getName() << " signed 📝 " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << "❌ " << getName() << " couldn't sign 📝 " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << "✅ " << getName() << " executed 📝 " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << "❌ " << getName() << " couldn't execute 📝 " << form.getName() << " because " << e.what() << std::endl;
    }
}

// ───────────────────────────────────── EXCEPTIONS ─────────────────────────────────────

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "⛔ Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "⛔ Grade too low!";
}