TARGET := libft.a
SRCDIR := src
OBJDIR := obj
INCLUDES := includes

SOURCES := $(shell find $(SRCDIR) -name 'ft_*.c')
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CC := clang
CFLAGS += -Wall -Wextra -Werror -O3
RM := rm -rf
AR := ar rcs

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) $(TARGET) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: clean fclean re
