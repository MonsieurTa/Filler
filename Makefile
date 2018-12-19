# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wta <wta@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 20:09:26 by wta               #+#    #+#              #
#    Updated: 2018/12/18 17:38:34 by wta              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#=======================================================================  COLOR#
_GREEN		=	\033[0;32m
_WHITE		=	\033[m
_YELLOW		=	\033[0;33m
_DYELLOW	=	\x1b[33;01m
#==================================================================== VARIABLES#
NAME		=	wta.filler
SRCSDIR		=	srcs
LIBFTPATH	=	libft
LIBFTLIB	=	libft.a
LIBFT		=	$(addprefix $(LIBFTPATH)/,$(LIBFTLIB))
INCDIR		=	includes
OBJDIR		=	objs
OBJ			=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
CC			=	gcc
INC			=	-I $(INCDIR) -I .
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=
HEADER		=
#======================================================================# RULES #
all : $(NAME)
#=======================================================================# NAME #
$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $@
	@echo "\n$(_GREEN)[CREATED]$(_WHITE)" $@
	@echo "All objects files are in $(_DYELLOW)obj$(_WHITE)/"
#===================================================================# MKDIROBJ #
$(OBJDIR) :
	@mkdir $@
	@echo "\n$(_YELLOW)[CREATED]$(_WHITE)" $@
#=====================================================================# FILLER #
$(addprefix $(OBJDIR)/,%.o) : $(addprefix $(SRCSDIR)/,%.c) $(addprefix $(INCDIR)/,$(HEADER)) | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "\r                                                              \r\c"
	@echo "$(_GREEN)[OK]$(_WHITE) $@\c"
#======================================================================# LIBFT #
$(LIBFT) :
	@make -C $(LIBFTPATH)
	@echo "\r                                                              \r\c"
	@echo "$(_GREEN)[OK]$(_WHITE) $@\c"
#======================================================================# CLEAN #
clean :
	@make -C $(LIBFTPATH) clean
	@echo "$(_DYELLOW)[CLEAN]$(_WHITE)" LIBFT
	@rm -f $(OBJ)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" OBJECTS
	@rm -rf $(OBJDIR)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" $(OBJDIR)/
#=====================================================================# FCLEAN #
fclean : clean
	@make -C $(LIBFTPATH) fclean
	@echo "$(_DYELLOW)[FCLEAN]$(_WHITE)" LIBFT
	@rm -f	$(NAME)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" $(NAME)
#=========================================================================# RE #
re : fclean all
#==============================================================================#