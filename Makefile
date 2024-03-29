#---------------------------------------------------------------------------------
# PAlib Project Makefile by Scognito, Tom, crash and fincs
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
# Please uncomment (i.e. delete the '#') only one "ARM7_SELECTED" line. If unsure,
# leave it as is (with ARM7_MP3 uncommented).
#---------------------------------------------------------------------------------

ARM7_SELECTED := ARM7_MP3
#ARM7_SELECTED := ARM7_MP3_DSWIFI
#ARM7_SELECTED := ARM7_MAXMOD_DSWIFI

#---------------------------------------------------------------------------------
# If you're using EFS uncomment "USE_EFS = YES" here.
#---------------------------------------------------------------------------------

#USE_EFS = YES

#---------------------------------------------------------------------------------
# Be sure to change these default banner TEXTs. This is the name your project will
# display in the DS menu (including some flash cards). Create a custom logo.bmp
# icon for your project too!
#---------------------------------------------------------------------------------

TEXT1 := FIRST Game Rebound Rumble
TEXT2 := For Year 2012
TEXT3 := Using NDSRAF (NDS Raguna Application Framework)

#---------------------------------------------------------------------------------
# TARGET is the name of the file to output
# BUILD is the directory where object files and intermediate files will be placed
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing extra header files
# AUDIO is a list of directories containing audio files for use with Maxmod
# RELEASEPATH is the output directory (Optional)
#---------------------------------------------------------------------------------

TARGET      := $(shell basename $(CURDIR))
BUILD       := build
SOURCES     := data gfx/bin ../../NDSRAF/source source
INCLUDES    := build data gfx ../../NDSRAF/include include
AUDIO       := audio
RELEASEPATH := 

#---------------------------------------------------------------------------------
# If you need to change other parts of the make process, see the PA_Makefile:
#---------------------------------------------------------------------------------

MAKEFILE_VER := ver1

include $(DEVKITPRO)/PAlib/lib/PA_Makefile
