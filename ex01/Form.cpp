#include "Form.hpp"
#include "Bureaucrat.hpp"

// Exception class definitions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form::Grade is higher than required!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form::Grade is lower than required!";
}

// Constructor
Form::Form()
    : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name.empty() ? "Default Form" : name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const char*  name, int gradeToSign, int gradeToExecute)
    : _name((!name || std::string(name).empty() ? "Default Form" : name)), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}
      

Form& Form::operator=(const Form& other) {
    if (this != &other) {
            this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form() {}

// Getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeRequiredToSign() const {
    return _gradeToSign;
}

int Form::getGradeRequiredToExecute() const {
    return _gradeToExecute;
}

// Function to sign the form
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

// Operator overload for printing
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade to sign: " << form.getGradeRequiredToSign() 
       << ", Grade to execute: " << form.getGradeRequiredToExecute();
    return os;
}

