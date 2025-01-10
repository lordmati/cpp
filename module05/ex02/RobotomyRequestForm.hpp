#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYRQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm:AForm
{
	private:
			std::string target;
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(const RobotomyRequestForm &data);
			RobotomyRequestForm &operator=(const RobotomyRequestForm &data);
			~RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			void execute(Bureaucrat const & executor) const;

};
#endif