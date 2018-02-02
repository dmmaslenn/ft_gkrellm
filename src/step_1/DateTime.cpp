#include "DateTime.hpp"

DateTime::DateTime() {
	setModuleName("Date");
	setModuleValue(checkValue());
}

DateTime::~DateTime() {

}

DateTime::DateTime(DateTime &) {

}

DateTime &DateTime::operator=(DateTime &src) {
	setModuleName(src.getModuleName());
	setModuleValue(src.getModuleValue());
	return *this;
}

std::string	DateTime::checkValue() {
	time_t     	now = time(0);
	tm  		tstruct;
	char		buf[30];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y.%m.%d %X", &tstruct);

	return buf;
}