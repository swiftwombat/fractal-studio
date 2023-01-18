#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#

# define the Cpp compiler to use
CXX = g++

# define any compile-time flags
CXXFLAGS	:= -std=c++17 -Wall -Wextra -g

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS 		 = -L"C:\SFML\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows
INCLUDES 	:= -I"C:\SFML\include" -DSFML_STATIC

EXE			:= FractalStudio.exe
BINDIR		:= bin
OBJDIR		:= obj
SRCDIR		:= src

subdirs = $(filter-out $1,$(sort $(dir $(wildcard $1*/))))
rfind = $(wildcard $1$2) $(foreach d,$(call subdirs,$1),$(call rfind,$d,$2))


RM			:= del /q /f
MD			:= mkdir

FIXPATH 	 = $(subst /,\,$1)
EXEPATH		:= $(call FIXPATH,$(BINDIR)/$(EXE))
SOURCES 	:= $(call rfind,$(SRCDIR)/,*.cpp)
OBJECTS 	:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: build
	./$(EXEPATH)
	@echo Run complete!

build: $(BINDIR) $(OBJDIR) $(EXEPATH)
	@echo Build complete!

$(EXEPATH): $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJECTS) -o $(EXEPATH)  $(LFLAGS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.SECONDEXPANSION:
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $$(@D)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BINDIR):
	@$(MD) $@

$(OBJDIR):
	@$(MD) $(subst /,\,$(patsubst %/, %, $(sort $(dir $(OBJECTS)))))

.PHONY: clean
clean:
	$(RM) $(EXEPATH)
	$(RM) $(call FIXPATH,$(OBJECTS))
	@echo Cleanup complete!