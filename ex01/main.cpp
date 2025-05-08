# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
   try {

      std::cout <<"\nTest 1: Valid grade to sign" << std::endl;
      Bureaucrat alice("Alice", 45);
      Form taxForm("Tax Form", 50, 30);
      std::cout << alice;
      alice.signForm(taxForm);
      std::cout << taxForm << std::endl;
             
      std::cout <<"\nTest 2: Invalid grade to sign" << std::endl;
      Bureaucrat bob("Bob", 100);
      Form topSecret("Top Secret Form", 30, 10);
      std::cout << bob;
      bob.signForm(topSecret);
      std::cout << topSecret << std::endl;
    
  } catch (std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
  }
   return(0);
}
