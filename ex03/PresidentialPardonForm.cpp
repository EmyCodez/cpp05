# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <ctime>

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5),_target("") {
        throw AForm::EmptyTargetException();
    }

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5) {
    if (target.empty()) {
        throw AForm::EmptyTargetException();  
    }
    _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const char *target)
: AForm("PresidentialPardonForm", 25, 5), 
      _target((!target || std::string(target).empty() ? throw AForm::EmptyTargetException() : target)) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

        std::cout << BLUE << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

