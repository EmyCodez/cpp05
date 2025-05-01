# include <iostream>
# include "Bureaucrat.hpp"

int main()
{
    try 
     {
        //Test 1: Valid name and grade
        std::cout << "Test 1: Valid name and grade" << std::endl;
        Bureaucrat b1("Alice", 42);
        std::cout << b1 << std::endl;

        // Test 2: Increment grade within range
        std::cout << "Test 2: Increment grade within range" << std::endl;
        Bureaucrat b2("Diana", 3);
        b2.incrementGrade(2);  
        std::cout << b2 << std::endl;

       // Test 3: Decrement grade within range
       std::cout << "Test 3: Decrement grade within range" << std::endl;
       Bureaucrat b3("Fiona", 148);
       b3.decrementGrade(1); 
       b3.decrementGrade(1); 
       std::cout << b3 << std::endl;

     }catch (std::exception &e) {
       std::cout << "Exception: " << e.what() << std::endl;
     }

     // Invalid Cases
     try
     {
        // Test 4: Grade too high during construction
        std::cout << "Test 4: Grade too high during construction" << std::endl;
        Bureaucrat b2("Bob", 0);
     }catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
     }

     try
     {
        // Test 5: Grade too low during construction
        std::cout << "\nTest 5: Grade too low during construction" << std::endl;
        Bureaucrat b5("Charlie", 151);
     }catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
     }

    try
     {
        // Test 6: Increment beyond upper limit
        std::cout << "\nTest 6: Increment beyond upper limit" << std::endl;
        Bureaucrat b6("Edward", 2);
        b6.incrementGrade(2); 
     }catch(const std::exception& e)
     {
        std::cout << "Exception: " << e.what() << std::endl;
     }
     
     try
     {
        // Test 7: Decrement beyond lower limit
        std::cout << "\nTest 7: Decrement beyond lower limi" << std::endl;
        Bureaucrat b7("George", 149);
        b7.decrementGrade(2);
     }catch (std::exception &e)
     {
       std::cout << "Exception: " << e.what() << std::endl;
     }

   return(0);
}
