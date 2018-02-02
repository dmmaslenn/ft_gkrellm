#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "AMonitorModule.hpp"

class DateTime : public AMonitorModule{
public:
	DateTime();
	~DateTime();
	DateTime(DateTime &);
	DateTime &operator=(DateTime & src);
	std::string checkValue();
};


#endif
