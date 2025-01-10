#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
			std::string target;
	public:
			PresidentialPardonForm();
			PresidentialPardonForm(const PresidentialPardonForm &data);
			PresidentialPardonForm &operator=(const PresidentialPardonForm &data);
			~PresidentialPardonForm();
			PresidentialPardonForm(std::string target);
			void execute(Bureaucrat const & executor) const;
};
#endif