### YOUR SETTINGS ###
#
# Edit the settings to your needs

# Your project name (no whitespace)
PROJECT 	= tresor
# Programmer device
PORT 		= /dev/ttyACM0
# Compiler target (avr-gcc)
MMCU 		= atmega8
# Programmer type
PROGRAMMER 	= stk500
# Programmer target
TARGET 		= m8
# Optimization
OPTIMIZATION = s

# avr-libc toolchain
AVR_TOOLCHAIN 	= /usr/share/avr
# avrdude
DUDE 			= /usr/bin/avrdude

### YOUR DEPENDENCIES ###
#
# Add the name of the used modules from your include directory
# 
# Example:
# MODULES = fourier integration 
MODULES = future leds coil reset_btn

# Any c libs that you wand to include
# Example:
# LIBS = -lm
LIBS=

# DO NOT TOUCH ANYTHING AFTER THIS

# TOOLCHAIN LINKS
LIBC = $(AVR_TOOLCHAIN)/avr/include
CC = $(AVR_TOOLCHAIN)/bin/avr-gcc
LD = $(AVR_TOOLCHAIN)/bin/avr-objcopy

# SEARCH PATHS
DOCDIR = ../doc/doxygen/out
IDIR = ../inc
LDIR = ../lib
BDIR = bin
ODIR = obj
_DEPS = $(MODULES)
_OBJS = $(MODULES) main
DEPS = $(patsubst %,$(IDIR)/%.h,$(_DEPS))
OBJS = $(patsubst %,$(ODIR)/%.o,$(_OBJS))

# FLAGS
LDFLAGS = -j .text -j .data -O ihex
CFLAGS = --sysroot=$(LIBC) -mmcu=$(MMCU) -O$(OPTIMIZATION)
PFLAGS = -p $(TARGET) -c $(PROGRAMMER) -P $(PORT) -e -v 

all: $(OBJS)
	@echo CC $(basename $(notdir $^))
	@$(CC) $(CFLAGS) -Os $^ -o $(ODIR)/$(PROJECT).o
		
	@echo LD $(basename $(notdir $(PROJECT)))
	@mkdir -p $(BDIR)
	@$(LD) $(LDFLAGS) $(ODIR)/$(PROJECT).o $(BDIR)/$(PROJECT).hex

	@echo 
	@echo Your file was compiled to \'bin/$(PROJECT).hex\'.
	@echo Run \'make download\' to download your program to \'$(PORT)\'.

$(ODIR)/%.o: %.c $(DEPS)
	@echo CC $(basename $(notdir $<))
	@$(CC) $(CFLAGS) $(LIBS) -c $< -o $@
	
download:
	$(DUDE) $(PFLAGS) -U flash:w:$(BDIR)/$(PROJECT).hex
	
github:
	@mkdir $(ODIR)
doc:
	@cd $(DOCDIR); doxygen
.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ $(BDIR)/*.hex
	rm -rf $(DOCDIR)/*
