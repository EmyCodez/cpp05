#include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define YELLOW "\033[33m"
#define RESET  "\033[0m"


//Constructors
RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45)
{
    if (_target.empty())
        throw AForm::EmptyTargetException();
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45),_target(target) {
    if (_target.empty())
        throw AForm::EmptyTargetException();
}

RobotomyRequestForm::RobotomyRequestForm(const char* target)
    : AForm("RobotomyRequestForm", 72, 45), 
      _target((!target || std::string(target).empty() ? throw AForm::EmptyTargetException() : target)) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other), _target(other._target){}

RobotomyRequestForm&::RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        AForm::operator=(other); 
        _target = other._target;
    }
return *this;
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << YELLOW << "Bzzzzzz... *drilling noises*" << RESET << std::endl;

    if (std::rand() % 2 == 0) {
            std::cout << YELLOW << _target << " has been robotomized successfully!" << RESET << std::endl;
    } else {
            std::cout << YELLOW << "Robotomy failed on " << _target << "." << RESET << std::endl;
    }
}