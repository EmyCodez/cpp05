#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
    
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const char* target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;
};

