# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macbook/CLionProjects/SERIAL_R

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbook/CLionProjects/SERIAL_R/cmake-build-debug

# Utility rule file for SERIAL_R-burn.

# Include the progress variables for this target.
include CMakeFiles/SERIAL_R-burn.dir/progress.make

CMakeFiles/SERIAL_R-burn: SERIAL_R.elf
	/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -cstk500v2 -Pusb -patmega2560 -v -Uflash:w:/Users/macbook/CLionProjects/SERIAL_R/cmake-build-debug/SERIAL_R.hex

SERIAL_R-burn: CMakeFiles/SERIAL_R-burn
SERIAL_R-burn: CMakeFiles/SERIAL_R-burn.dir/build.make

.PHONY : SERIAL_R-burn

# Rule to build all files generated by this target.
CMakeFiles/SERIAL_R-burn.dir/build: SERIAL_R-burn

.PHONY : CMakeFiles/SERIAL_R-burn.dir/build

CMakeFiles/SERIAL_R-burn.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SERIAL_R-burn.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SERIAL_R-burn.dir/clean

CMakeFiles/SERIAL_R-burn.dir/depend:
	cd /Users/macbook/CLionProjects/SERIAL_R/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macbook/CLionProjects/SERIAL_R /Users/macbook/CLionProjects/SERIAL_R /Users/macbook/CLionProjects/SERIAL_R/cmake-build-debug /Users/macbook/CLionProjects/SERIAL_R/cmake-build-debug /Users/macbook/CLionProjects/SERIAL_R/cmake-build-debug/CMakeFiles/SERIAL_R-burn.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SERIAL_R-burn.dir/depend

