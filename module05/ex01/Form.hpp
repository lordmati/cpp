#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"


class Bureaucrat;
class Form
{
	private:
		const std::string name;
		bool sign;
		const int sigit;
		const int exeit;
	public:
		Form();
		Form &operator=(const Form &data);
		Form (const Form &data);
		Form(const char *nameP,const int sigitP,const int exeitP);
		std::string getName() const;
		bool getSign();
		int getSigit() const;
		int getExeit() const;
		void beSigned(Bureaucrat &person);
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
		~Form();

};
std::ostream& operator<<(std::ostream& ret, Form& data);
std::string IntToString(int num);
std::string BoolToString(bool data);
#endif