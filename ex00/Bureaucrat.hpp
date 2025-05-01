# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class GradeTooHighException : public std::exception
{
public:
    const char* what() const throw();
};

class GradeTooLowException : public std::exception
{
public:
    const char* what() const throw();
};

class Bureaucrat 
{
private:
    std::string const _name;
    int _grade;
    
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator= (const Bureaucrat &other);
    ~Bureaucrat();

    //getters
    const std::string& getName() const;
    int getGrade() const;

    //member functions
    void incrementGrade(int value);
    void decrementGrade(int value);
};

//overloaded insertion operator
std::ostream &operator<< (std::ostream &os, const Bureaucrat &other);

# endif