#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Static helper methods to create forms
AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}


// Constructors, destructor, and assignment
Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

// makeForm implementation
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    typedef AForm* (*FormCreator)(const std::string&);
    FormCreator creators[3] = {
        &Intern::createPresidentialForm,
        &Intern::createRobotomyForm,
        &Intern::createShrubberyForm
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << BLUE << "Intern creates " << formName << " form."<< RESET << std::endl;
            return creators[i](target);
        }
    }
    throw AForm::FormNotFoundException();
}
