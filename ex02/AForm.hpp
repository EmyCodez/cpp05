#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

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
        
    // Constructor
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

    // Function to sign the form
    void beSigned(const Bureaucrat& bureaucrat);

    // Virtual functions
    virtual void execute(Bureaucrat const & executor) const = 0;
   
};

 // Operator overload for printing
 std::ostream& operator << (std::ostream& os, const AForm& other);

#endif 
