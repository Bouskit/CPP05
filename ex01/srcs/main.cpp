#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        printTitle("Création de Bureaucrat et Form valides");
        Bureaucrat b("Alice", 42);
        Form f("Contrat A", 50, 30);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
    }

    {
        printTitle("Création de Bureaucrat invalide (grade trop bas)");
        try {
            Bureaucrat b("Bob", 151);
        } catch (const std::exception& e) {
            printException(e);
        }
    }

    {
        printTitle("Création de Form invalide (grade trop haut)");
        try {
            Form f("Contrat B", 0, 30);
        } catch (const std::exception& e) {
            printException(e);
        }
    }

    {
        printTitle("Signature réussie");
        Bureaucrat b("Charlie", 30);
        Form f("Formulaire C", 40, 25);
        b.signForm(f);
        std::cout << f << std::endl;
    }

    {
        printTitle("Signature échouée (grade trop bas)");
        Bureaucrat b("David", 100);
        Form f("Formulaire D", 50, 20);
        b.signForm(f);
        std::cout << f << std::endl;
    }

    {
        printTitle("Signature double d’un même formulaire");
        Bureaucrat b("Emma", 10);
        Form f("Formulaire E", 50, 20);
        b.signForm(f);
        b.signForm(f);
        std::cout << f << std::endl;
    }

    return 0;
}
