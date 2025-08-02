#include "ShrubberyCreationForm.hpp"

// ─────────────────────────────────── CONSTRUCTORS ───────────────────────────────────

ShrubberyCreationForm::ShrubberyCreationForm() {
    AForm::AForm("ShrubberyCreation", 145, 137);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) {
    AForm::AForm(name, 145, 137);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
    // TODO: copy constructor
}

// ─────────────────────────────────── DESTRUCTORS ────────────────────────────────────

ShrubberyCreationForm::~ShrubberyCreationForm() {
    // TODO: destructor
}

// ───────────────────────────────────── OPERATORS ─────────────────────────────────────

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        // TODO: assignment logic
    }
    return *this;
}

// ───────────────────────────────── GETTERS / SETTERS ─────────────────────────────────

// ───────────────────────────────────── FUNCTIONS ─────────────────────────────────────
