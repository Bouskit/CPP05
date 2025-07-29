#include "Bureaucrat.hpp"

// ──────────── COULEURS TERMINAL ─────────────
#define RESET   "\033[0m"
#define CYAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"

// ──────────── AFFICHAGE UTILITAIRE ──────────
void printTitle(const std::string& msg) {
    std::cout << CYAN << "\n=== " << msg << " ===\n" << RESET << std::endl;
}

void printException(const std::exception& e) {
    std::cout << YELLOW << "Exception capturée : " << e.what() << RESET << std::endl;
}

// ──────────── MAIN TESTS ─────────────────────
int main() {
    {
        printTitle("Construction Valide");
        Bureaucrat a("Alice", 75);
        std::cout << a << std::endl;
    }

    {
        printTitle("Construction Invalide (grade trop bas)");
        try {
            Bureaucrat b("Bob", 151);
        } catch (const std::exception& e) {
            printException(e);
        }
    }

    {
        printTitle("Construction Invalide (grade trop haut)");
        try {
            Bureaucrat c("Carl", 0);
        } catch (const std::exception& e) {
            printException(e);
        }
    }

    {
        printTitle("Test incrementGrade / decrementGrade");
        try {
            Bureaucrat d("Diana", 2);
            std::cout << d << std::endl;
            d.incrementGrade();
            std::cout << "Après increment : " << d << std::endl;
            d.incrementGrade();
        } catch (const std::exception& e) {
            printException(e);
        }

        try {
            Bureaucrat e("Eric", 149);
            std::cout << e << std::endl;
            e.decrementGrade();
            std::cout << "Après decrement : " << e << std::endl;
            e.decrementGrade();
        } catch (const std::exception& e) {
            printException(e);
        }
    }

    return 0;
}


