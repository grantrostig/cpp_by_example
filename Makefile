# ==== Begin prologue boilerplate.
#NAME := lib_tty  // not used?
#MAJOR := 1  // not used?
#MINOR := 1  // not used?
#VERSION := $(MAJOR).$(MINOR)  // not used?

all : # The canonical default target.
BUILD := debug
build_dir := ${CURDIR}/${BUILD}
exes := # Executables to build.
STDCXX := -std=c++2b
#STDCXX := -std=gnu++20
# ==== End prologue boilerplate.

# ==== Begin define executable my_exe.
exes += my_exe
objects.my_exe = main.o game.o Mymy_exe.o space.o
-include ${objects.my_exe:%.o=${build_dir}/%.d} # Include auto-generated dependencies.
# ==== End define executable my_exe.

# ==== Begin define another executable.
# ... as for my_exe
# ==== End define another executable.

# ==== Begin rest of boilerplate.
SHELL := /bin/bash
COMPILER=gcc

CXX.gcc := /usr/bin/g++
CC.gcc  := /usr/bin/gcc
LD.gcc  := /usr/bin/g++
AR.gcc  := /usr/bin/ar

CXX.clang := /usr/bin/clang++
CC.clang  := /usr/bin/clang
LD.clang  := /usr/bin/clang++
AR.clang  := /usr/bin/ar

CXX := ${CXX.${COMPILER}}
CC := ${CC.${COMPILER}}
LD := ${LD.${COMPILER}}
AR := ${AR.${COMPILER}}

CXXFLAGS.gcc.debug   := -Og -fstack-protector-all
CXXFLAGS.gcc.release := -O3 -march=native -DNDEBUG
CXXFLAGS.gcc         := -pthread ${STDCXX} -march=native -W{all,extra,error,pedantic} -g -fmessage-length=0 ${CXXFLAGS.gcc.${BUILD}}
# CPPFLAGS :=   -fPIC  \ -g   -fconcepts \

CXXFLAGS.clang.debug   := -O0 -fstack-protector-all
CXXFLAGS.clang.release := -O3 -march=native -DNDEBUG
CXXFLAGS.clang         := -pthread -std=gnu++14 -march=native -W{all,extra,error} -g -fmessage-length=0 ${CXXFLAGS.clang.${BUILD}}

CXXFLAGS := ${CXXFLAGS.${COMPILER}}
CFLAGS := ${CFLAGS.${COMPILER}}

LDFLAGS.debug   :=
LDFLAGS.release :=
LDFLAGS         := -fuse-ld=gold -pthread -g ${LDFLAGS.${BUILD}}
LDLIBS          := -ldl

COMPILE.CXX = ${CXX} -c -o $@ ${CPPFLAGS} -MD -MP ${CXXFLAGS} $(abspath $<)
PREPROCESS.CXX = ${CXX} -E -o $@ ${CPPFLAGS} ${CXXFLAGS} $(abspath $<)
COMPILE.C = ${CC} -c -o $@ ${CPPFLAGS} -MD -MP ${CFLAGS} $(abspath $<)
LINK.EXE = ${LD} -o $@ $(LDFLAGS) $(filter-out Makefile,$^) $(LDLIBS)
LINK.SO = ${LD} -shared -o $@ $(LDFLAGS) $(filter-out Makefile,$^) $(LDLIBS)
LINK.A = ${AR} rsc $@ $(filter-out Makefile,$^)

all : ${exes:%=${build_dir}/%} # Build all exectuables.

.SECONDEXPANSION:
# Build an executable.
${exes:%=${build_dir}/%} : ${build_dir}/% : $$(addprefix ${build_dir}/,$${objects.$$*}) Makefile | ${build_dir}
    $(strip ${LINK.EXE})

# Run an executable. E.g. make run_my_exe
${exes:%=run_%} : run_% : ${build_dir}/%
    @echo "---- running $< ----"
    /usr/bin/time --verbose $<

# Create the build directory on demand.
${build_dir} :
    mkdir $@

# Compile a C++ source into .o.
# Most importantly, generate header dependencies.
${build_dir}/%.o : %.cpp Makefile | ${build_dir}
    $(strip ${COMPILE.CXX})

# Compile a C source into .o.
# Most importantly, generate header dependencies.
${build_dir}/%.o : %.c Makefile | ${build_dir}
    $(strip ${COMPILE.C})

clean :
    rm -rf ${build_dir}

.PHONY : clean all run_%

# ==== End rest of boilerplate.

# ==== MORE stuff for so libraries??
#lib: lib$(NAME).so.$(VERSION)
#
#test: $(NAME)_test
#	LD_LIBRARY_PATH=. ./$(NAME)_test
#
#$(NAME)_test: lib$(NAME).so
#	$(CC) $(NAME)_test.c -o $@ -L. -l$(NAME)
#
#lib$(NAME).so: lib$(NAME).so.$(VERSION)
#	ldconfig -v -n .
#	ln -s lib$(NAME).so.$(MAJOR) lib$(NAME).so
#
#lib$(NAME).so.$(VERSION): $(NAME).o
#	$(CC) -shared -Wl,-soname,lib$(NAME).so.$(MAJOR) $^ -o $@
