#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;  // Forward declaration

class Form {
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

    // Constructor
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const char* name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator= (const Form& other);
    ~Form();

    // Getters
    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeRequiredToSign() const;
    int getGradeRequiredToExecute() const;

    // Function to sign the form
    void beSigned(const Bureaucrat& bureaucrat);
   
};

 // Operator overload for printing
 std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
