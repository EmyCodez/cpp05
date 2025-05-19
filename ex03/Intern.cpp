#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Static helper functions 
static AForm* createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

static AForm* createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createShrubberyForm(const std::string& target) {
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

// makeform function
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    const std::string formNames[3] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    // Array of function pointers to static form creators
    typedef AForm* (*FormCreator)(const std::string&);
    FormCreator creators[3] = {
        &createPresidentialForm,
        &createRobotomyForm,
        &createShrubberyForm
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << BLUE << "Intern creates " << formName << " form."<< RESET << std::endl;
            return creators[i](target);
        }
    }
    throw AForm::FormNotFoundException();
}
