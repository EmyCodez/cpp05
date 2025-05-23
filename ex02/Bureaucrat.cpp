# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <iostream>

// Exception class definitions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat::Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat::Grade too low!";
}

// Constructors
Bureaucrat::Bureaucrat() :_name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) 
        : _name(name.empty() ? "Default Bureaucrat" : name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const char *name, int grade) 
        : _name( (!name || std::string(name).empty()) ? "Default Bureaucrat" : name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    this->_grade = other._grade;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
            this->_grade = other._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getter functions
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Member functions to modify grade
void Bureaucrat::incrementGrade() {
    if (_grade <= 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

//Function to sign form
void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn’t sign " << form << " because " << e.what() << std::endl;
    }
}

// Function to execute a form
void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn’t execute " << form << " because " << e.what() << std::endl;
    }
}

//overloaded insertion operator
std::ostream &operator<< (std::ostream &os, const Bureaucrat &other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (os);
}