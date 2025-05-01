# include "Bureaucrat.hpp"

const char* GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

Bureaucrat::Bureaucrat() :_name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name.empty()? "Default" : name)
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
void Bureaucrat::incrementGrade() {
    if(_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;    
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
           throw GradeTooLowException();
    _grade++;    
}


//overloaded insertion operator
std::ostream &operator<< (std::ostream &os, const Bureaucrat &other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return (os);
}