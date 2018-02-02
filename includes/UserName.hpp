#ifndef USERNAME_HPP
#define USERNAME_HPP

#include "AMonitorModule.hpp"

class UserName : public  AMonitorModule{
public:
	UserName();
	~UserName();
	UserName(UserName &);
	UserName &operator=(UserName & src);
	std::string checkValue();
};


#endif