# include "Bureaucrat.hpp"

const char* GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

Bureaucrat::Bureaucrat() :_name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :_name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &other)
{
    if (this != &other) {
           _grade = other._grade;
    }
    return(*this);
}

Bureaucrat::~Bureaucrat(){}

//getters
const std::string& Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

//member functions
void Bureaucrat::incrementGrade(int value) {
    if(_grade - value < 1)
        throw GradeTooHighException();
    _grade -= value;    
}

void Bureaucrat::decrementGrade(int value) {
    if (_grade + value > 150)
           throw GradeTooLowException();
    _grade += value;    
}


//overloaded insertion operator
std::ostream &operator<< (std::ostream &os, const Bureaucrat &other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (os);
}