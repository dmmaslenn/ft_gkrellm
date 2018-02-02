#all rule

#Colors tags
GREENTAG:="\033[1;32m"
YELLOWTAG:="\033[1;33m"
REDTAG:="\033[1;31m"
CENDTAG:="\033[0;0m"
#-----------

#Binary name
NAME = ft_gkrellm
#Compiler and compiler flags
CC = clang++
CFLAGS = -lncurses -Wall -Wextra -Werror

#Project structure directories
IDIR = includes
ODIR = obj
SDIR = src
#All project sources list (norminette demand)
SRCS = AMonitorModule.cpp \
       CPUInfo.cpp \
       main.cpp \
       NetworkInfo.cpp \
       PhysMemory.cpp \
       step_1/DateTime.cpp \
       step_1/HostName.cpp \
       step_1/OsInfo.cpp \
       step_1/UserName.cpp \
       Window.cpp \

#Creating objects path
OBJS := $(patsubst %.cpp,$(ODIR)/%.o,$(SRCS))

#Compiling object files
$(ODIR)/%.o:$(SDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo $(YELLOWTAG)"|\c"
	@$(CC) -I$(IDIR) -c $< -o $@

#Linking binary, adding libs etc.
$(NAME):$(OBJS)
	@echo $(CENDTAG)
	@echo $(GREENTAG)"Linking project..."
	@$(CC) -o $@ $^ $(CFLAGS) -pg
	@echo "Done."$(CENDTAG)

#defining order and checking that obj dir exists
$(OBJS): | $(ODIR)
#creating obj dir if not exist
$(ODIR):
	@mkdir -p $(ODIR)

all: $(NAME)

#clean rule
clean:
	@echo $(YELLOWTAG)"Cleaning project..."
	@rm -rf $(ODIR)
	@echo "Done."$(CENDTAG)
#full clean rule
fclean: clean
	@rm -rf $(NAME)
	@echo $(REDTAG)"Project deleted."$(CENDTAG)
#norminette rule
#re rule
re: clean all
#phony defend
.PHONY: all clean fclean re norm
