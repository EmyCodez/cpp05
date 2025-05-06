#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

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
    
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getter functions
    const std::string& getName() const;
    int getGrade() const;

    // Member functions
    void incrementGrade();
    void decrementGrade();
    // Function to sign a form
    void signForm(Form& form);
};

//overloaded insertion operator
std::ostream &operator<< (std::ostream &os, const Bureaucrat &other);

#endif // BUREAUCRAT_HPP
