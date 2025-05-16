#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Exception class definitions
#include "AForm.hpp"

// Implement all what() messages
const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm::Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm::Grade is too low.";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm::Form has not been signed.";
}

const char* AForm::FileNotOpenedException::what() const throw() {
    return "AForm::File could not be opened.";
}

const char* AForm::EmptyTargetException::what() const throw() {
    return "AForm::Target cannot be empty.";
}

// Constructor
AForm::AForm()
    : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name.empty() ? "Default Form" : name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

AForm::AForm(const char*  name, int gradeToSign, int gradeToExecute)
    : _name((!name || std::string(name).empty() ? "Default Form" : name)), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), 
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}
      

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
            this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

// Getters
const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// Function to sign the form
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

// Operator overload for printing
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl
       << "Grade to sign: " << form.getGradeToSign() 
       << ", Grade to execute: " << form.getGradeToExecute() <<" ";
    return (os);
}    
