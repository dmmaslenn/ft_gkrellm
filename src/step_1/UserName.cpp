#include "UserName.hpp"

UserName::UserName() {
	setModuleName("Username");
	setModuleValue(checkValue());
}

UserName::~UserName() {

}

UserName::UserName(UserName &) {

}

UserName &UserName::operator=(UserName &src) {
	setModuleName(src.getModuleName());
	setModuleValue(src.getModuleValue());
	return *this;
}

std::string UserName::checkValue() {
	char tmp[BUFFSIZE];

	getlogin_r(tmp, BUFFSIZE);
	std::string ret(tmp);
	return ret;
}