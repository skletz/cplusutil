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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/fbfb0bc5/DateTime.o \
	${OBJECTDIR}/_ext/fbfb0bc5/Directory.o \
	${OBJECTDIR}/_ext/fbfb0bc5/File.o \
	${OBJECTDIR}/_ext/fbfb0bc5/FileIO.o \
	${OBJECTDIR}/_ext/fbfb0bc5/String.o \
	${OBJECTDIR}/_ext/fbfb0bc5/Terminal.o \
	${OBJECTDIR}/_ext/fbfb0bc5/demo.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-cplusutil.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-cplusutil.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-cplusutil.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-cplusutil.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lib-cplusutil.a

${OBJECTDIR}/_ext/fbfb0bc5/DateTime.o: ../cplusutil/src/DateTime.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/fbfb0bc5
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fbfb0bc5/DateTime.o ../cplusutil/src/DateTime.cpp

${OBJECTDIR}/_ext/fbfb0bc5/Directory.o: ../cplusutil/src/Directory.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/fbfb0bc5
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fbfb0bc5/Directory.o ../cplusutil/src/Directory.cpp

${OBJECTDIR}/_ext/fbfb0bc5/File.o: ../cplusutil/src/File.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/fbfb0bc5
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fbfb0bc5/File.o ../cplusutil/src/File.cpp

${OBJECTDIR}/_ext/fbfb0bc5/FileIO.o: ../cplusutil/src/FileIO.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/fbfb0bc5
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fbfb0bc5/FileIO.o ../cplusutil/src/FileIO.cpp

${OBJECTDIR}/_ext/fbfb0bc5/String.o: ../cplusutil/src/String.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/fbfb0bc5
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fbfb0bc5/String.o ../cplusutil/src/String.cpp

${OBJECTDIR}/_ext/fbfb0bc5/Terminal.o: ../cplusutil/src/Terminal.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/fbfb0bc5
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fbfb0bc5/Terminal.o ../cplusutil/src/Terminal.cpp

${OBJECTDIR}/_ext/fbfb0bc5/demo.o: ../cplusutil/src/demo.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/fbfb0bc5
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/fbfb0bc5/demo.o ../cplusutil/src/demo.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
