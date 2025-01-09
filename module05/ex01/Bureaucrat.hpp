#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include "Form.hpp"

class Bureaucrat
{
	private:
			const std::string name;
			int grade;
	public:
			Bureaucrat();
			Bureaucrat(const Bureaucrat &data);
			Bureaucrat(const char *nameP,int range);
			Bureaucrat &operator=(const Bureaucrat &data);
			const std::string getName();
			int getGrade();
			~Bureaucrat();
			void incrementRange(void);
			void decrementRange(void);
			void signForm(Form &data);
			class GradeTooHighException : public std::exception
			{
				public:
						const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				public:
						const char *what() const throw();
			};
};
std::ostream& operator<<(std::ostream& ret, Bureaucrat& data);
#endif