#include "HostName.hpp"
#include "UserName.hpp"
#include "DateTime.hpp"
#include "OsInfo.hpp"
#include "CPUInfo.hpp"
#include "PhysMemory.hpp"
#include "Window.hpp"
#include "NetworkInfo.hpp"

int		ft_loop(Window win) {
	int loop = true;
	HostName	h;
	UserName	u;
	DateTime	d;
	OsInfo		o;
	CPUInfo		c;
	PhysMemory  m;
	NetworkInfo  n;
	while(loop)
	{
		loop = win.keyHook();
		///STATIC
		mvprintw(2, 5, "%s : %s", h.getModuleName().c_str(), h.getModuleValue().c_str());
		mvprintw(3, 5, "%s : %s", u.getModuleName().c_str(), u.getModuleValue().c_str());
		mvprintw(5, 5, "%s: \n%s\n", o.getModuleName().c_str(), o.getModuleValue().c_str());
		mvprintw(10, 5, "%s : %s", c.getModuleName().c_str(), c.getModuleValue().c_str());
		mvprintw(11, 5, "%s : Core: %d", c.getModuleName().c_str(), c.getConcurentThreadsSupported());
		///Dynamic
		mvprintw(3, static_cast<int>(win.getW() - d.getModuleName().length() - d.getModuleValue().length() - 5), "%s : %s", d.getModuleName().c_str(), d.checkValue().c_str());
		mvprintw(12, 5, "%s : %s", c.getModuleName().c_str(), c.CPUGetLoad().c_str());
		mvprintw(13, 5, "%s :\n\t%s", m.getModuleName().c_str(), m.checkValue().c_str());
		mvprintw(15, 5, "%s :\n\t%s", n.getModuleName().c_str(), n.checkValue().c_str());
		box(stdscr, 0, 0);
		refresh();
		usleep(30000);
	}
	return (1);
}

int main(){

	Window		win;

	ft_loop(win);
	return 0;
}