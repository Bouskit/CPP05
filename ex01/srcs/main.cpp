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
    
    return 0;
}


