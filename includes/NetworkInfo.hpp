#ifndef RUSH01_NETWORKINFO_HPP
#define RUSH01_NETWORKINFO_HPP

#include "AMonitorModule.hpp"
#include <iomanip>
#include <sstream>


class NetworkInfo : public AMonitorModule{
public:
	NetworkInfo();
	~NetworkInfo();
	NetworkInfo(NetworkInfo &);
	NetworkInfo &operator=(NetworkInfo & src);
	std::string checkValue();
};

#endif
