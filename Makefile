##
## EPITECH PROJECT, 2021
## B-NWP-400-LIL-4-1-myftp-hugo.humez
## File description:
## Makefile
##

ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[1;31m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"

CC              =       gcc -g3

RM              =       rm -f

NAME            =       myteams_server

C_NAME            =       myteams_cli

CXXFLAGS	+=  -I./include -ggdb3
CXXFLAGS	+=	-Wextra -Wall -W

S_DIR = ./server/

C_DIR = ./client/

S_SRC             =       $(S_DIR)src/main.c \
						  $(S_DIR)src/teams.c \
						  $(S_DIR)src/socket.c \
						  $(S_DIR)src/clients.c \
						  $(S_DIR)src/communication.c \
						  $(S_DIR)src/linked_list/linked_list.c \
						  $(S_DIR)src/linked_list/linked_list2.c \
						  $(S_DIR)src/linked_list/list_functions.c \
						  $(S_DIR)src/linked_list/channels_list.c \
						  $(S_DIR)src/linked_list/get_context.c \
						  $(S_DIR)src/linked_list/replies_list.c \
						  $(S_DIR)src/linked_list/teams_list.c \
						  $(S_DIR)src/linked_list/threads_list.c \
						  $(S_DIR)src/functions/connexions.c \
						  $(S_DIR)src/functions/user_handle.c \
						  $(S_DIR)src/functions/discuss.c \
						  $(S_DIR)src/functions/helper.c \
						  $(S_DIR)src/functions/updating_file.c \
						  $(S_DIR)src/functions/create.c \
						  $(S_DIR)src/functions/use.c \
						  $(S_DIR)src/functions/list.c \
						  $(S_DIR)src/functions/functions_tools.c \
						  $(S_DIR)src/tools.c \
						  $(S_DIR)src/logging_out_clients.c \
						  $(S_DIR)src/cleaning.c \
						  $(S_DIR)src/fetch_save_groups.c

C_SRC             =       $(C_DIR)src/main.c \
						  $(C_DIR)src/socket.c \
						  $(C_DIR)src/execution.c \
						  $(C_DIR)src/server_setup.c \
						  $(C_DIR)src/functions/setter.c \
						  $(C_DIR)src/functions/create_groups.c \
						  $(C_DIR)src/communications.c \
						  $(S_DIR)src/linked_list/list_functions.c \
						  $(C_DIR)src/functions/discuss.c \
						  $(C_DIR)src/functions/message_list.c \
						  $(C_DIR)src/functions/errors_client.c \
						  $(S_DIR)src/tools.c

OBJ             =       $(S_SRC:.c=.o)

C_OBJ			=	    $(C_SRC:.c=.o)

all             :	src_server $(NAME) src_client $(C_NAME)

src_client		:
			@$(ECHO) $(TEAL) "\nCLIENT FILES" $(DEFAULT)

src_server		:
			@$(ECHO) $(TEAL) "SERVER FILES" $(DEFAULT)

$(NAME)         :	$(OBJ)
			@$(CC) -luuid -L./libs/myteams -lmyteams -o $(NAME) $(OBJ) $(CXXFLAGS) && \
			 $(ECHO) $(YELLOW) "[OK]" $(BLUE) $(NAME) $(DEFAULT)  || \
			 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME) $(DEFAULT)

$(C_NAME)         :	$(C_OBJ)
			@$(CC) -luuid -L./libs/myteams -lmyteams -o $(C_NAME) $(C_OBJ) $(CXXFLAGS) && \
			 $(ECHO) $(YELLOW) "[OK]" $(BLUE) $(C_NAME) $(DEFAULT)  || \
			 $(ECHO) $(RED) "[XX]" $(TEAL) $(C_NAME) $(DEFAULT)

clean           :
			@rm -f $(OBJ)
			@rm -f $(C_OBJ)

fclean          :       clean
			@$(RM) $(NAME)
			@$(RM) $(C_NAME)

re              :       fclean all

.PHONY         :       all clean fclean re

.c.o		:
			@$(CC) $(CXXFLAGS) -L./libs/myteams -lmyteams -ggdb3 -c $< -o $@  && \
			 $(ECHO) $(YELLOW) "[OK]" $(BLUE) $< $(DEFAULT) || \
			 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)