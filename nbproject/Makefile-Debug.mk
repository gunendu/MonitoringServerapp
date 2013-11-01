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
	${OBJECTDIR}/cfgparser.o \
	${OBJECTDIR}/ipcpublisher.o \
	${OBJECTDIR}/serverConnectThread3.o \
	${OBJECTDIR}/Controller.o \
	${OBJECTDIR}/logger.o \
	${OBJECTDIR}/copyStructure.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/DBConnection.o \
	${OBJECTDIR}/StartLineProcess.o \
	${OBJECTDIR}/MonitoringSupport.o \
	${OBJECTDIR}/ConnectAdapaterThread.o \
	${OBJECTDIR}/ddsinterface.o \
	${OBJECTDIR}/commonfunctions.o \
	${OBJECTDIR}/serverConnectThread2.o \
	${OBJECTDIR}/MonitoringPlugin.o \
	${OBJECTDIR}/serverConnectThread.o \
	${OBJECTDIR}/Monitoring.o \
	${OBJECTDIR}/basicthread.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -g3 -pg
CXXFLAGS=-m64 -g3 -pg

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/opt/rti/ndds.4.5f/lib/x64Linux2.6gcc4.4.3 -L/usr/local/lib -L/home/dunendhu/tbb40_20120613oss/lib/intel64/cc4.1.0_libc2.4_kernel2.6.16.21 -Wl,-rpath /opt/rti/ndds.4.5f/lib/x64Linux2.6gcc4.4.3 -Wl,-rpath /usr/local/lib -Wl,-rpath /home/dunendhu/tbb40_20120613oss/lib/intel64/cc4.1.0_libc2.4_kernel2.6.16.21 -lnddscppzd -lnddsczd -lnddscorezd -ldl -lnsl -lpq -lssh2 -lpthread -lrt -ltbb -ltbbmalloc

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -static-libgcc -pg -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/cfgparser.o: cfgparser.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/cfgparser.o cfgparser.cc

${OBJECTDIR}/ipcpublisher.o: ipcpublisher.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/ipcpublisher.o ipcpublisher.cpp

${OBJECTDIR}/serverConnectThread3.o: serverConnectThread3.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/serverConnectThread3.o serverConnectThread3.cpp

${OBJECTDIR}/Controller.o: Controller.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Controller.o Controller.cpp

${OBJECTDIR}/logger.o: logger.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/logger.o logger.cpp

${OBJECTDIR}/copyStructure.o: copyStructure.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/copyStructure.o copyStructure.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/DBConnection.o: DBConnection.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/DBConnection.o DBConnection.cpp

${OBJECTDIR}/StartLineProcess.o: StartLineProcess.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/StartLineProcess.o StartLineProcess.cpp

${OBJECTDIR}/MonitoringSupport.o: MonitoringSupport.cxx 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/MonitoringSupport.o MonitoringSupport.cxx

${OBJECTDIR}/ConnectAdapaterThread.o: ConnectAdapaterThread.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/ConnectAdapaterThread.o ConnectAdapaterThread.cpp

${OBJECTDIR}/ddsinterface.o: ddsinterface.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/ddsinterface.o ddsinterface.cpp

${OBJECTDIR}/commonfunctions.o: commonfunctions.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/commonfunctions.o commonfunctions.cpp

${OBJECTDIR}/serverConnectThread2.o: serverConnectThread2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/serverConnectThread2.o serverConnectThread2.cpp

${OBJECTDIR}/MonitoringPlugin.o: MonitoringPlugin.cxx 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/MonitoringPlugin.o MonitoringPlugin.cxx

${OBJECTDIR}/serverConnectThread.o: serverConnectThread.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/serverConnectThread.o serverConnectThread.cpp

${OBJECTDIR}/Monitoring.o: Monitoring.cxx 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Monitoring.o Monitoring.cxx

${OBJECTDIR}/basicthread.o: basicthread.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -DRTI_64BIT -DRTI_LINUX -DRTI_UNIX -DSTD_STL -D__STDC_FORMAT_MACROS -I/opt/rti/ndds.4.5f/include/ndds -I/opt/rti/ndds.4.5f/include -I../../tbb40_20120613oss/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/basicthread.o basicthread.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
