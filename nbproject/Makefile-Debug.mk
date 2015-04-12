#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/courbe_elliptique.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/point.o \
	${OBJECTDIR}/multmodp.o \
	${OBJECTDIR}/gnu_plot_example.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11 -lgmp -lgmpxx
CXXFLAGS=-std=c++11 -lgmp -lgmpxx

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/cygwin/home/Bastian/gnuplot2/gnuplot_i/src -L/usr/include/x86_64-linux-gnu -L/usr/include -lgmp -lgmpxx

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/travaille-de-bachelor

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/travaille-de-bachelor: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	g++  -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/travaille-de-bachelor ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/courbe_elliptique.o: courbe_elliptique.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/c++ -I/usr/include/x86_64-linux-gnu -I/usr/include/c++/4.8 -MMD -MP -MF $@.d -o ${OBJECTDIR}/courbe_elliptique.o courbe_elliptique.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/c++ -I/usr/include/x86_64-linux-gnu -I/usr/include/c++/4.8 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/point.o: point.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/c++ -I/usr/include/x86_64-linux-gnu -I/usr/include/c++/4.8 -MMD -MP -MF $@.d -o ${OBJECTDIR}/point.o point.cpp

${OBJECTDIR}/multmodp.o: multmodp.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/c++ -I/usr/include/x86_64-linux-gnu -I/usr/include/c++/4.8 -MMD -MP -MF $@.d -o ${OBJECTDIR}/multmodp.o multmodp.cpp

${OBJECTDIR}/gnu_plot_example.o: gnu_plot_example.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/include/c++ -I/usr/include/x86_64-linux-gnu -I/usr/include/c++/4.8 -MMD -MP -MF $@.d -o ${OBJECTDIR}/gnu_plot_example.o gnu_plot_example.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/travaille-de-bachelor

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
