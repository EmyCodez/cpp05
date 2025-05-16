#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RED   "\033[31m"
#define RESET  "\033[0m"



class Bureaucrat;

class AForm {
private: 
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FileNotOpenedException : public std::exception {
    public:
        const char* what() const throw();
    };

    class EmptyTargetException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Constructors / Destructor
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const char* name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator= (const AForm& other);
    virtual ~AForm() = 0;

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Form signing
    void beSigned(const Bureaucrat& bureaucrat);

    // Execution interface
    virtual void execute(Bureaucrat const& executor) const = 0;
};

// Output stream operator
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif 
