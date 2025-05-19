# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main() {
        Intern intern;
        AForm *form;
    
        form = intern.makeForm("robotomy request", "Bender");
        if (form)
            delete form;
    
        try {
               AForm* form = intern.makeForm("nonexistent form", "target");
               if (form)
               delete form;
            }catch (const std::exception& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
        return 0;
    }
     
