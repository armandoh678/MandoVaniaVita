TARGET		:= mandovania
TITLE		:= MANDV0001
GIT_VERSION := $(shell git describe --abbrev=6 --dirty --always --tags)
PSVITAIP 	:=192.168.0.19
LIBS = -lvita2d -lSceDisplay_stub -lSceGxm_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub -lScePvf_stub \
	-lSceCommonDialog_stub -lfreetype -lpng -ljpeg -lz -lm -lc  -lbox2d
INC=-I/castleengine/
CPPSOURCES	:= ./

CFILES	:=
#CPPFILES   := $(foreach dir,$(CPPSOURCES), $(wildcard $(dir)/*.cpp))
CPPFILES	:=  $(wildcard castleengine/*.cpp) $(wildcard castleengine/render/*.cpp) $(wildcard castleengine/chars/*.cpp) $(wildcard *.cpp)
BINFILES := $(foreach dir,$(DATA), $(wildcard $(dir)/*.bin))
OBJS     := $(addsuffix .o,$(BINFILES)) $(CFILES:.c=.o) $(CPPFILES:.cpp=.o)

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CXX      = $(PREFIX)-g++
CFLAGS  = -Wl,-q -O2 -g -mtune=cortex-a9 -mfpu=neon
CXXFLAGS  = $(INC) $(CFLAGS) -fno-exceptions -std=gnu++11
ASFLAGS = $(CFLAGS)

all: $(TARGET).vpk

$(TARGET).vpk: $(TARGET).velf
	vita-make-fself -s $< build/eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE) "$(TARGET)" param.sfo
	cp -f param.sfo build/sce_sys/param.sfo

	#------------ Comment this if you don't have 7zip ------------------
	#7z a -tzip ./$(TARGET).vpk -r ./build/sce_sys ./build/eboot.bin
	#-------------------------------------------------------------------
	vita-pack-vpk -s ./build/sce_sys/param.sfo -b ./build/eboot.bin $@
%.velf: %.elf
	cp $< $<.unstripped.elf
	$(PREFIX)-strip -g $<
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

clean:
	@rm -rf $(TARGET).velf $(TARGET).elf $(OBJS) $(TARGET).elf.unstripped.elf $(TARGET).vpk build/eboot.bin build/sce_sys/param.sfo ./param.sfo


send:
	curl -T build/eboot.bin ftp://$(PSVITAIP):1337/ux0:/app/$(TITLE)/
	@echo "Sent."
