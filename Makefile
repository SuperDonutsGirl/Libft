# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 04:15:26 by pamartin          #+#    #+#              #
#    Updated: 2021/12/10 04:15:33 by pamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a
HEADER	= 	libft.h

CC 			= 	gcc
FLAG 		= 	-Wall -Wextra -Werror
OPTION 		= 	-I $(HEADER) -c

####        MENDATORY	PART
SRC 		= 	ft_isalpha.c		ft_isdigit.c 		ft_isalnum.c \
				ft_isprint.c		ft_toupper.c		ft_tolower.c \
				ft_isascii.c		ft_atoi.c			ft_strlen.c \
				ft_strncmp.c		ft_strchr.c			ft_strrchr.c \
				ft_memcmp.c			ft_memchr.c			ft_memset.c \
				ft_strnstr.c		ft_bzero.c			ft_strdup.c \
				ft_substr.c			ft_strjoin.c		ft_strtrim.c \
				ft_strmapi.c		ft_striteri.c		ft_putchar_fd.c \
				ft_putstr_fd.c		ft_putendl_fd.c 	ft_split.c \
				ft_putnbr_fd.c		ft_memcpy.c			ft_calloc.c \
				ft_itoa.c			ft_memmove.c 		ft_strlcpy.c \
				ft_strlcat.c	

OBJ 		= 	${SRC:.c=.o}

####		BONUS		PART
BONUS 		= 	ft_lstnew.c			ft_lstsize.c		ft_lstlast.c \
				ft_lstiter.c		ft_lstadd_front.c	ft_lstadd_back.c \
				ft_lstdelone.c		ft_lstclear.c 		ft_lstmap.c

BONUSOBJ	= ${BONUS:.c=.o}

.c.o:
	${CC} ${FLAG} ${OPTION} $< -o ${<:.c=.o}


${NAME}:	${OBJ}
		ar -rc ${NAME} ${OBJ}

all:		${NAME}

clean:
		rm  ${OBJ}
		
fclean: 	clean
		rm  ${NAME}

re:		fclean all

bonus: ${OBJ} ${BONUSOBJ}
	ar -rc ${NAME} ${OBJ} ${BONUSOBJ}


.PHONY:	all clean fclean re bonus
