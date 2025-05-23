# include <iostream>
#include <ctime>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
    
    // -------------- ShrubberyCreationForm --------------- //
    std::cout << RED << "\n============ Shrubberry Creation =========\n" << RESET;
    std::cout << "Case 1: Valid grade \n"; 
    try
    {
        Bureaucrat	bureaucrat("Alice", 46);
		std::cout << bureaucrat;
		ShrubberyCreationForm	shrubbery("Office");
		bureaucrat.signForm(shrubbery);
		bureaucrat.executeForm(shrubbery);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\nCase 2: Invalid grade \n";
    try
    {
        Bureaucrat	bob("Bob", 146);
		std::cout << bob;
		ShrubberyCreationForm	shrubbery("Home");
		bob.signForm(shrubbery);
		bob.executeForm(shrubbery);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  
    // -------------- RobotomyRequestForm --------------- //
    std::cout << RED << "\n============ Robotomy Request =========\n" << RESET;
    std::cout << "Case 1: Valid grade \n";
    try
    {
        
        Bureaucrat	bureaucrat("Anne", 36);
		std::cout << bureaucrat;
		RobotomyRequestForm	rob1("Home");
		bureaucrat.signForm(rob1);
		bureaucrat.executeForm(rob1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\nCase 2: Invalid grade \n";
    try
    {
        Bureaucrat	bob("Bob", 136);
		std::cout << bob;
        RobotomyRequestForm	robot("Home");
		bob.signForm(robot);
		bob.executeForm(robot);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << RED << "\n============ Presidential Pardon =========\n" << RESET;
    std::cout << "Case 1: Valid grade \n";
    try {
        Bureaucrat bureaucrat("Zaphod", 1);
        std::cout << bureaucrat;
        PresidentialPardonForm pardon("Joey"); 
        bureaucrat.signForm(pardon);
        bureaucrat.executeForm(pardon); 
    }
    catch (const AForm::EmptyTargetException& e) {
        std::cerr << "Exception: " << e.what() << std::endl;  
    }
    std::cout << "\nCase 2: Invalid grade \n";
    try {
        Bureaucrat bob("Bob", 15);
        std::cout << bob;
        PresidentialPardonForm pardon("Joey"); 
        bob.signForm(pardon);
        bob.executeForm(pardon); 
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
   return (0);
}