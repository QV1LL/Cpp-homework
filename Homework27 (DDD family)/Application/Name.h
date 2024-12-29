#pragma once

namespace Project {

	class Name
	{
	private:

		std::string firstName;
		std::string lastName;

	public:

		Name(const std::string& firstName,
			const std::string& lastName) {
			if (lastName.empty() || firstName.empty())
				throw gcnew System::ArgumentException("First or last name cannot be empty!");

			this->firstName = firstName;
			this->lastName = lastName;
		}

		operator std::string() const { return this->firstName + " " + this->lastName; }
		std::ostream& operator<<(std::ostream& out) const { return out << std::string(*this); }
	};
}

