#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("NAME")
{
	std::cout << "Bureaucrat constructor" << std::endl;
	this->grade = 0;
}
Bureaucrat::Bureaucrat(const Bureaucrat &data):name(data.name)
{
	std::cout << "Bureaucrat constructor copy" << std::endl;
	if (this != &data)
		*this = data;
}
Bureaucrat::Bureaucrat(const char *name_p,int range):name(name_p)
{
	this->grade = range;
	try
	{
		if(range < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (range > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(std::exception & e)
	{	
		std::cerr << e.what();
	}
}
void Bureaucrat::incrementRange(void)
{
	this->grade--;
	try
	{
		if(this->grade < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (this->grade > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(std::exception & e)
	{	
		std::cerr << e.what();
	}
}
void Bureaucrat::decrementRange(void)
{
	this->grade++;
	try
	{
		if(this->grade < 1)
			throw(Bureaucrat::GradeTooHighException());
		else if (this->grade > 150)
			throw(Bureaucrat::GradeTooLowException());
	}
	catch(std::exception & e)
	{	
		std::cerr << e.what();
	}
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &data)
{
	std::cout << "Bureaucrat assignament operator" << std::endl;
	this->grade = data.grade;
	return(*this);
}
const std::string Bureaucrat::getName()
{
	return(this->name);
}
int Bureaucrat::getGrade()
{
	return(this->grade);
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Error: Low\n");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Error: High\n");
}
std::ostream& operator<<(std::ostream& ret,Bureaucrat& data)
{
	std::ostringstream oss;
	std::string str;
	oss << data.getGrade();
	str = oss.str();
	ret << data.getName() + ", bureaucrat grade " + str;
	return(ret);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}