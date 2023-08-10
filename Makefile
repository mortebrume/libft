CC = gcc
CFLAGS += -Wall -Wextra -Werror
SRCS = $(wildcard ft_i*.c) $(wildcard ft_m*.c) $(wildcard ft_p*.c) \
					$(wildcard ft_s*.c) $(wildcard ft_t*.c) \
					ft_atoi.c ft_bzero.c ft_calloc.c
SRCS_B = $(wildcard *_bonus.c)
OBJECTS = $(SRCS:.c=.o)
OBJECTS_B = $(SRCS_B:.c=.o)
TARGET = libft.a
RM = rm -f
AR = ar rcs

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS_B)

fclean: clean
	$(RM) $(TARGET)
	$(RM) libft.so

so:
	$(CC) -c -fPIC $(CFLAGS) $(SRCS) $(SRCS_B)
	gcc -nostartfiles -shared -o libft.so $(OBJECTS) $(OBJECTS_B)

re: fclean all

bonus: all $(OBJECTS_B)
	$(AR) $(TARGET) $(OBJECTS_B)

.PHONY: clean fclean bonus so re
