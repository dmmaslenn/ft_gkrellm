#ifndef HOSTNAME_HPP
#define HOSTNAME_HPP

#include "AMonitorModule.hpp"

class HostName : public  AMonitorModule{
public:
	HostName();
	~HostName();
	HostName(HostName &);
	HostName &operator=(HostName & src);
	std::string checkValue();

};


#endif
