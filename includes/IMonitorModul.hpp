#include <string>
#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# define BUFFSIZE 1024

class IMonitorModule {
public:
	virtual std::string checkValue() = 0;
private:

};


#endif
