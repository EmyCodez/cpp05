# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137)
    {
        if (_target.empty())
        throw AForm::EmptyTargetException();
    }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137),
     _target(target.empty() ? throw AForm::EmptyTargetException() : target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const char * target)
    : AForm("ShrubberyCreationForm", 145, 137),
      _target( (!target || std::string(target).empty() ? throw AForm::EmptyTargetException() : target)) {}     

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
    : AForm(other), _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other) 
{
    if (this != &other) {
        AForm::operator=(other); 
        _target = other._target;
    }
return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}    

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    // Create ASCII trees in a file
    std::ofstream file(_target + "_shrubbery");
    if (file.is_open()) {
       file << "        ,,,                      ,,,\n"
            << "   {{{}}    ,,,             {{{}}    ,,,\n"
            << " ,,, ~Y~    {{{}},,,      ,,, ~Y~    {{{}},,, \n"
            << "  {{}}} |/,,,  ~Y~{{}}}    {{}}} |/,,,  ~Y~{{}}}\n"
            << "   ~Y~ \\|{{}}}/\\|/ ~Y~  ,,, ~Y~ \\|{{}}}/\\|/ ~Y~  ,,,\n"
            << "   \\|/ \\|/~Y~  \\|,,,|/ {{}}}\\|/ \\|/~Y~  \\|,,,|/ {{}}}\n"
            << "   \\|/ \\|/\\|/  \\{{{}}/  ~Y~ \\|/ \\|/\\|/  \\{{{}}/  ~Y~\n"
            << "   \\|/\\\\|/\\|/ \\\\|~Y~//  \\|/ \\|/\\\\|/\\|/ \\\\|~Y~//  \\|/\n"
            << "   \\|//\\|/\\|/,\\\\|/|// \\|/ \\|//\\|/\\|/,\\\\|/|/|// \\|/\n"
            << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        file.close();
        std::cout << GREEN << "Shrubbery created at " << _target << "_shrubbery" << RESET << std::endl;
    } else {
        throw FileNotOpenedException();
    }
}
