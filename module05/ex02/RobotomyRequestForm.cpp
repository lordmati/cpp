#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():target("TARGET")
{
	std::cout << "RobotomyRequestForm Constructor" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &data):AForm("RobotomyRequestForm",72,45),target(data.target)
{
	std::cout << "Constructor copy RobotomyRequestForm" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &data)
{
	std::cout << "RobotomyRequestForm Constructor Operator" << std::endl;
	if(this != &data)
		*this = data;
	return(*this);
}
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm",72,45)
{
	std::cout << "Constructor RobotomyRequestForm target" << std::endl;
	this->target = target;
}
void RobotomyRequestForm::execute(Bureaucrat const & execute) const
{
	try
	{
		if(execute.getGrade() > this->getExeit())
			throw(AForm::GradeTooLowException()); //AGREGAR MAS COSAS
		if(this->getSign() == true)
		{
			srand((int)time(0));
			std::cout << "* drilling noises *" << std::endl;
			if(rand() % 2 == 0)
				std::cout << this->target << " has been robotomized" << std::endl;
			else
				std::cout << "NO SE ROBOTIZO" << std::endl;
		}
		else
			std::cout << "It is not signed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor RobotomyRequestForm" << std::endl;
}