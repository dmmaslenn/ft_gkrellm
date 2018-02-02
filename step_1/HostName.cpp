#include "HostName.hpp"

HostName::HostName() {
	setModuleName("Hostname");
	setModuleValue(checkValue());
}

HostName::~HostName() {

}

HostName::HostName(HostName &) {

}

HostName &HostName::operator=(HostName &src) {
	setModuleName(src.getModuleName());
	setModuleValue(src.getModuleValue());
	return *this;
}

std::string HostName::checkValue() {
	char tmp[BUFFSIZE];

	gethostname(tmp, BUFFSIZE);
	std::string ret(tmp);
	return ret;
}
