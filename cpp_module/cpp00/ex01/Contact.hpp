#ifndef CONTACT
#define CONTACT

#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void showInfo() const;
		void showsubInfo(int index) const;
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecrete(void) const;
		void setFirstName(std::string& firstName);
		void setLastName(std::string& lastName);
		void setNickname(std::string& nickname);
		void setPhoneNumber(std::string& phoneNumber);
		void setDarkestSecrete(std::string& darkestSecret);
};
#endif