TARGET := libft.a
SRCDIR := src
OBJDIR := obj
INCLUDES := includes

-include make/sources.mk
OBJECTS := ${SOURCES:%.c=${OBJDIR}/%.o}

CC := cc
CFLAGS += -Wall -Wextra -Werror
RM := rm -rf
AR := ar rcs

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(AR) $(TARGET) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(TARGET)


gmk:
	@if [ -d make ];then echo ok;else mkdir make;fi
	@find -name '*.c' -printf "%d%p\n" | sort -n | grep -v libft | grep -v mlx | sed 's/^[[:digit:]]/SOURCES += /' > make/sources.mk

re: fclean all

.PHONY: clean fclean gmk re
