# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Project\Travel_Agency

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Project\Travel_Agency

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	"C:\Program Files\JetBrains\CLion 2018.3\bin\cmake\win\bin\cmake.exe" -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	"C:\Program Files\JetBrains\CLion 2018.3\bin\cmake\win\bin\cmake.exe" -E echo "No interactive CMake dialog available."
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start E:\Project\Travel_Agency\CMakeFiles E:\Project\Travel_Agency\CMakeFiles\progress.marks
	$(MAKE) -f CMakeFiles\Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start E:\Project\Travel_Agency\CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles\Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles\Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Travel_Agency

# Build rule for target.
Travel_Agency: cmake_check_build_system
	$(MAKE) -f CMakeFiles\Makefile2 Travel_Agency
.PHONY : Travel_Agency

# fast build rule for target.
Travel_Agency/fast:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/build
.PHONY : Travel_Agency/fast

Admin/AdminPanels/Profile/profileEdit.obj: Admin/AdminPanels/Profile/profileEdit.cpp.obj

.PHONY : Admin/AdminPanels/Profile/profileEdit.obj

# target to build an object file
Admin/AdminPanels/Profile/profileEdit.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/Profile/profileEdit.cpp.obj
.PHONY : Admin/AdminPanels/Profile/profileEdit.cpp.obj

Admin/AdminPanels/Profile/profileEdit.i: Admin/AdminPanels/Profile/profileEdit.cpp.i

.PHONY : Admin/AdminPanels/Profile/profileEdit.i

# target to preprocess a source file
Admin/AdminPanels/Profile/profileEdit.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/Profile/profileEdit.cpp.i
.PHONY : Admin/AdminPanels/Profile/profileEdit.cpp.i

Admin/AdminPanels/Profile/profileEdit.s: Admin/AdminPanels/Profile/profileEdit.cpp.s

.PHONY : Admin/AdminPanels/Profile/profileEdit.s

# target to generate assembly for a file
Admin/AdminPanels/Profile/profileEdit.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/Profile/profileEdit.cpp.s
.PHONY : Admin/AdminPanels/Profile/profileEdit.cpp.s

Admin/AdminPanels/drivers.obj: Admin/AdminPanels/drivers.cpp.obj

.PHONY : Admin/AdminPanels/drivers.obj

# target to build an object file
Admin/AdminPanels/drivers.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/drivers.cpp.obj
.PHONY : Admin/AdminPanels/drivers.cpp.obj

Admin/AdminPanels/drivers.i: Admin/AdminPanels/drivers.cpp.i

.PHONY : Admin/AdminPanels/drivers.i

# target to preprocess a source file
Admin/AdminPanels/drivers.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/drivers.cpp.i
.PHONY : Admin/AdminPanels/drivers.cpp.i

Admin/AdminPanels/drivers.s: Admin/AdminPanels/drivers.cpp.s

.PHONY : Admin/AdminPanels/drivers.s

# target to generate assembly for a file
Admin/AdminPanels/drivers.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/drivers.cpp.s
.PHONY : Admin/AdminPanels/drivers.cpp.s

Admin/AdminPanels/offers.obj: Admin/AdminPanels/offers.cpp.obj

.PHONY : Admin/AdminPanels/offers.obj

# target to build an object file
Admin/AdminPanels/offers.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/offers.cpp.obj
.PHONY : Admin/AdminPanels/offers.cpp.obj

Admin/AdminPanels/offers.i: Admin/AdminPanels/offers.cpp.i

.PHONY : Admin/AdminPanels/offers.i

# target to preprocess a source file
Admin/AdminPanels/offers.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/offers.cpp.i
.PHONY : Admin/AdminPanels/offers.cpp.i

Admin/AdminPanels/offers.s: Admin/AdminPanels/offers.cpp.s

.PHONY : Admin/AdminPanels/offers.s

# target to generate assembly for a file
Admin/AdminPanels/offers.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/offers.cpp.s
.PHONY : Admin/AdminPanels/offers.cpp.s

Admin/AdminPanels/setting.obj: Admin/AdminPanels/setting.cpp.obj

.PHONY : Admin/AdminPanels/setting.obj

# target to build an object file
Admin/AdminPanels/setting.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/setting.cpp.obj
.PHONY : Admin/AdminPanels/setting.cpp.obj

Admin/AdminPanels/setting.i: Admin/AdminPanels/setting.cpp.i

.PHONY : Admin/AdminPanels/setting.i

# target to preprocess a source file
Admin/AdminPanels/setting.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/setting.cpp.i
.PHONY : Admin/AdminPanels/setting.cpp.i

Admin/AdminPanels/setting.s: Admin/AdminPanels/setting.cpp.s

.PHONY : Admin/AdminPanels/setting.s

# target to generate assembly for a file
Admin/AdminPanels/setting.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/setting.cpp.s
.PHONY : Admin/AdminPanels/setting.cpp.s

Admin/AdminPanels/tickets.obj: Admin/AdminPanels/tickets.cpp.obj

.PHONY : Admin/AdminPanels/tickets.obj

# target to build an object file
Admin/AdminPanels/tickets.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/tickets.cpp.obj
.PHONY : Admin/AdminPanels/tickets.cpp.obj

Admin/AdminPanels/tickets.i: Admin/AdminPanels/tickets.cpp.i

.PHONY : Admin/AdminPanels/tickets.i

# target to preprocess a source file
Admin/AdminPanels/tickets.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/tickets.cpp.i
.PHONY : Admin/AdminPanels/tickets.cpp.i

Admin/AdminPanels/tickets.s: Admin/AdminPanels/tickets.cpp.s

.PHONY : Admin/AdminPanels/tickets.s

# target to generate assembly for a file
Admin/AdminPanels/tickets.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/tickets.cpp.s
.PHONY : Admin/AdminPanels/tickets.cpp.s

Admin/AdminPanels/transaction.obj: Admin/AdminPanels/transaction.cpp.obj

.PHONY : Admin/AdminPanels/transaction.obj

# target to build an object file
Admin/AdminPanels/transaction.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/transaction.cpp.obj
.PHONY : Admin/AdminPanels/transaction.cpp.obj

Admin/AdminPanels/transaction.i: Admin/AdminPanels/transaction.cpp.i

.PHONY : Admin/AdminPanels/transaction.i

# target to preprocess a source file
Admin/AdminPanels/transaction.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/transaction.cpp.i
.PHONY : Admin/AdminPanels/transaction.cpp.i

Admin/AdminPanels/transaction.s: Admin/AdminPanels/transaction.cpp.s

.PHONY : Admin/AdminPanels/transaction.s

# target to generate assembly for a file
Admin/AdminPanels/transaction.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/transaction.cpp.s
.PHONY : Admin/AdminPanels/transaction.cpp.s

Admin/AdminPanels/trips.obj: Admin/AdminPanels/trips.cpp.obj

.PHONY : Admin/AdminPanels/trips.obj

# target to build an object file
Admin/AdminPanels/trips.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/trips.cpp.obj
.PHONY : Admin/AdminPanels/trips.cpp.obj

Admin/AdminPanels/trips.i: Admin/AdminPanels/trips.cpp.i

.PHONY : Admin/AdminPanels/trips.i

# target to preprocess a source file
Admin/AdminPanels/trips.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/trips.cpp.i
.PHONY : Admin/AdminPanels/trips.cpp.i

Admin/AdminPanels/trips.s: Admin/AdminPanels/trips.cpp.s

.PHONY : Admin/AdminPanels/trips.s

# target to generate assembly for a file
Admin/AdminPanels/trips.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/trips.cpp.s
.PHONY : Admin/AdminPanels/trips.cpp.s

Admin/AdminPanels/users.obj: Admin/AdminPanels/users.cpp.obj

.PHONY : Admin/AdminPanels/users.obj

# target to build an object file
Admin/AdminPanels/users.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/users.cpp.obj
.PHONY : Admin/AdminPanels/users.cpp.obj

Admin/AdminPanels/users.i: Admin/AdminPanels/users.cpp.i

.PHONY : Admin/AdminPanels/users.i

# target to preprocess a source file
Admin/AdminPanels/users.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/users.cpp.i
.PHONY : Admin/AdminPanels/users.cpp.i

Admin/AdminPanels/users.s: Admin/AdminPanels/users.cpp.s

.PHONY : Admin/AdminPanels/users.s

# target to generate assembly for a file
Admin/AdminPanels/users.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/AdminPanels/users.cpp.s
.PHONY : Admin/AdminPanels/users.cpp.s

Admin/admin.obj: Admin/admin.cpp.obj

.PHONY : Admin/admin.obj

# target to build an object file
Admin/admin.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/admin.cpp.obj
.PHONY : Admin/admin.cpp.obj

Admin/admin.i: Admin/admin.cpp.i

.PHONY : Admin/admin.i

# target to preprocess a source file
Admin/admin.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/admin.cpp.i
.PHONY : Admin/admin.cpp.i

Admin/admin.s: Admin/admin.cpp.s

.PHONY : Admin/admin.s

# target to generate assembly for a file
Admin/admin.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/admin.cpp.s
.PHONY : Admin/admin.cpp.s

Admin/adminlogged.obj: Admin/adminlogged.cpp.obj

.PHONY : Admin/adminlogged.obj

# target to build an object file
Admin/adminlogged.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/adminlogged.cpp.obj
.PHONY : Admin/adminlogged.cpp.obj

Admin/adminlogged.i: Admin/adminlogged.cpp.i

.PHONY : Admin/adminlogged.i

# target to preprocess a source file
Admin/adminlogged.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/adminlogged.cpp.i
.PHONY : Admin/adminlogged.cpp.i

Admin/adminlogged.s: Admin/adminlogged.cpp.s

.PHONY : Admin/adminlogged.s

# target to generate assembly for a file
Admin/adminlogged.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Admin/adminlogged.cpp.s
.PHONY : Admin/adminlogged.cpp.s

BankAccounts/account_func.obj: BankAccounts/account_func.cpp.obj

.PHONY : BankAccounts/account_func.obj

# target to build an object file
BankAccounts/account_func.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/BankAccounts/account_func.cpp.obj
.PHONY : BankAccounts/account_func.cpp.obj

BankAccounts/account_func.i: BankAccounts/account_func.cpp.i

.PHONY : BankAccounts/account_func.i

# target to preprocess a source file
BankAccounts/account_func.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/BankAccounts/account_func.cpp.i
.PHONY : BankAccounts/account_func.cpp.i

BankAccounts/account_func.s: BankAccounts/account_func.cpp.s

.PHONY : BankAccounts/account_func.s

# target to generate assembly for a file
BankAccounts/account_func.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/BankAccounts/account_func.cpp.s
.PHONY : BankAccounts/account_func.cpp.s

Cities/city.obj: Cities/city.cpp.obj

.PHONY : Cities/city.obj

# target to build an object file
Cities/city.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Cities/city.cpp.obj
.PHONY : Cities/city.cpp.obj

Cities/city.i: Cities/city.cpp.i

.PHONY : Cities/city.i

# target to preprocess a source file
Cities/city.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Cities/city.cpp.i
.PHONY : Cities/city.cpp.i

Cities/city.s: Cities/city.cpp.s

.PHONY : Cities/city.s

# target to generate assembly for a file
Cities/city.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Cities/city.cpp.s
.PHONY : Cities/city.cpp.s

Drivers/drivers.obj: Drivers/drivers.cpp.obj

.PHONY : Drivers/drivers.obj

# target to build an object file
Drivers/drivers.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Drivers/drivers.cpp.obj
.PHONY : Drivers/drivers.cpp.obj

Drivers/drivers.i: Drivers/drivers.cpp.i

.PHONY : Drivers/drivers.i

# target to preprocess a source file
Drivers/drivers.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Drivers/drivers.cpp.i
.PHONY : Drivers/drivers.cpp.i

Drivers/drivers.s: Drivers/drivers.cpp.s

.PHONY : Drivers/drivers.s

# target to generate assembly for a file
Drivers/drivers.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Drivers/drivers.cpp.s
.PHONY : Drivers/drivers.cpp.s

UI/UI.obj: UI/UI.cpp.obj

.PHONY : UI/UI.obj

# target to build an object file
UI/UI.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/UI/UI.cpp.obj
.PHONY : UI/UI.cpp.obj

UI/UI.i: UI/UI.cpp.i

.PHONY : UI/UI.i

# target to preprocess a source file
UI/UI.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/UI/UI.cpp.i
.PHONY : UI/UI.cpp.i

UI/UI.s: UI/UI.cpp.s

.PHONY : UI/UI.s

# target to generate assembly for a file
UI/UI.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/UI/UI.cpp.s
.PHONY : UI/UI.cpp.s

Users/users.obj: Users/users.cpp.obj

.PHONY : Users/users.obj

# target to build an object file
Users/users.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Users/users.cpp.obj
.PHONY : Users/users.cpp.obj

Users/users.i: Users/users.cpp.i

.PHONY : Users/users.i

# target to preprocess a source file
Users/users.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Users/users.cpp.i
.PHONY : Users/users.cpp.i

Users/users.s: Users/users.cpp.s

.PHONY : Users/users.s

# target to generate assembly for a file
Users/users.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/Users/users.cpp.s
.PHONY : Users/users.cpp.s

main.obj: main.cpp.obj

.PHONY : main.obj

# target to build an object file
main.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/main.cpp.obj
.PHONY : main.cpp.obj

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/main.cpp.s
.PHONY : main.cpp.s

someThingNecessary.obj: someThingNecessary.cpp.obj

.PHONY : someThingNecessary.obj

# target to build an object file
someThingNecessary.cpp.obj:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/someThingNecessary.cpp.obj
.PHONY : someThingNecessary.cpp.obj

someThingNecessary.i: someThingNecessary.cpp.i

.PHONY : someThingNecessary.i

# target to preprocess a source file
someThingNecessary.cpp.i:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/someThingNecessary.cpp.i
.PHONY : someThingNecessary.cpp.i

someThingNecessary.s: someThingNecessary.cpp.s

.PHONY : someThingNecessary.s

# target to generate assembly for a file
someThingNecessary.cpp.s:
	$(MAKE) -f CMakeFiles\Travel_Agency.dir\build.make CMakeFiles/Travel_Agency.dir/someThingNecessary.cpp.s
.PHONY : someThingNecessary.cpp.s

# Help Target
help:
	@echo The following are some of the valid targets for this Makefile:
	@echo ... all (the default if no target is provided)
	@echo ... clean
	@echo ... depend
	@echo ... rebuild_cache
	@echo ... Travel_Agency
	@echo ... edit_cache
	@echo ... Admin/AdminPanels/Profile/profileEdit.obj
	@echo ... Admin/AdminPanels/Profile/profileEdit.i
	@echo ... Admin/AdminPanels/Profile/profileEdit.s
	@echo ... Admin/AdminPanels/drivers.obj
	@echo ... Admin/AdminPanels/drivers.i
	@echo ... Admin/AdminPanels/drivers.s
	@echo ... Admin/AdminPanels/offers.obj
	@echo ... Admin/AdminPanels/offers.i
	@echo ... Admin/AdminPanels/offers.s
	@echo ... Admin/AdminPanels/setting.obj
	@echo ... Admin/AdminPanels/setting.i
	@echo ... Admin/AdminPanels/setting.s
	@echo ... Admin/AdminPanels/tickets.obj
	@echo ... Admin/AdminPanels/tickets.i
	@echo ... Admin/AdminPanels/tickets.s
	@echo ... Admin/AdminPanels/transaction.obj
	@echo ... Admin/AdminPanels/transaction.i
	@echo ... Admin/AdminPanels/transaction.s
	@echo ... Admin/AdminPanels/trips.obj
	@echo ... Admin/AdminPanels/trips.i
	@echo ... Admin/AdminPanels/trips.s
	@echo ... Admin/AdminPanels/users.obj
	@echo ... Admin/AdminPanels/users.i
	@echo ... Admin/AdminPanels/users.s
	@echo ... Admin/admin.obj
	@echo ... Admin/admin.i
	@echo ... Admin/admin.s
	@echo ... Admin/adminlogged.obj
	@echo ... Admin/adminlogged.i
	@echo ... Admin/adminlogged.s
	@echo ... BankAccounts/account_func.obj
	@echo ... BankAccounts/account_func.i
	@echo ... BankAccounts/account_func.s
	@echo ... Cities/city.obj
	@echo ... Cities/city.i
	@echo ... Cities/city.s
	@echo ... Drivers/drivers.obj
	@echo ... Drivers/drivers.i
	@echo ... Drivers/drivers.s
	@echo ... UI/UI.obj
	@echo ... UI/UI.i
	@echo ... UI/UI.s
	@echo ... Users/users.obj
	@echo ... Users/users.i
	@echo ... Users/users.s
	@echo ... main.obj
	@echo ... main.i
	@echo ... main.s
	@echo ... someThingNecessary.obj
	@echo ... someThingNecessary.i
	@echo ... someThingNecessary.s
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles\Makefile.cmake 0
.PHONY : cmake_check_build_system

