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
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ConnectedComponent.o \
	${OBJECTDIR}/Datalog.o \
	${OBJECTDIR}/DirectedGraph.o \
	${OBJECTDIR}/Expression.o \
	${OBJECTDIR}/Input.o \
	${OBJECTDIR}/Lex.o \
	${OBJECTDIR}/Parameter.o \
	${OBJECTDIR}/Parse.o \
	${OBJECTDIR}/Predicate.o \
	${OBJECTDIR}/Query.o \
	${OBJECTDIR}/Rule.o \
	${OBJECTDIR}/RuleList.o \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/Table.o \
	${OBJECTDIR}/Token.o \
	${OBJECTDIR}/TokenType.o \
	${OBJECTDIR}/Tuple.o \
	${OBJECTDIR}/Utils.o \
	${OBJECTDIR}/Vertex.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f1

${TESTDIR}/TestFiles/f1: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ConnectedComponent.o: ConnectedComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ConnectedComponent.o ConnectedComponent.cpp

${OBJECTDIR}/Datalog.o: Datalog.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Datalog.o Datalog.cpp

${OBJECTDIR}/DirectedGraph.o: DirectedGraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DirectedGraph.o DirectedGraph.cpp

${OBJECTDIR}/Expression.o: Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Expression.o Expression.cpp

${OBJECTDIR}/Input.o: Input.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Input.o Input.cpp

${OBJECTDIR}/Lex.o: Lex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lex.o Lex.cpp

${OBJECTDIR}/Parameter.o: Parameter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parameter.o Parameter.cpp

${OBJECTDIR}/Parse.o: Parse.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parse.o Parse.cpp

${OBJECTDIR}/Predicate.o: Predicate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Predicate.o Predicate.cpp

${OBJECTDIR}/Query.o: Query.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Query.o Query.cpp

${OBJECTDIR}/Rule.o: Rule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rule.o Rule.cpp

${OBJECTDIR}/RuleList.o: RuleList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RuleList.o RuleList.cpp

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/Table.o: Table.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Table.o Table.cpp

${OBJECTDIR}/Token.o: Token.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Token.o Token.cpp

${OBJECTDIR}/TokenType.o: TokenType.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TokenType.o TokenType.cpp

${OBJECTDIR}/Tuple.o: Tuple.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tuple.o Tuple.cpp

${OBJECTDIR}/Utils.o: Utils.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Utils.o Utils.cpp

${OBJECTDIR}/Vertex.o: Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vertex.o Vertex.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/ConnectedComponent_nomain.o: ${OBJECTDIR}/ConnectedComponent.o ConnectedComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/ConnectedComponent.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ConnectedComponent_nomain.o ConnectedComponent.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/ConnectedComponent.o ${OBJECTDIR}/ConnectedComponent_nomain.o;\
	fi

${OBJECTDIR}/Datalog_nomain.o: ${OBJECTDIR}/Datalog.o Datalog.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Datalog.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Datalog_nomain.o Datalog.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Datalog.o ${OBJECTDIR}/Datalog_nomain.o;\
	fi

${OBJECTDIR}/DirectedGraph_nomain.o: ${OBJECTDIR}/DirectedGraph.o DirectedGraph.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DirectedGraph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DirectedGraph_nomain.o DirectedGraph.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DirectedGraph.o ${OBJECTDIR}/DirectedGraph_nomain.o;\
	fi

${OBJECTDIR}/Expression_nomain.o: ${OBJECTDIR}/Expression.o Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Expression_nomain.o Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Expression.o ${OBJECTDIR}/Expression_nomain.o;\
	fi

${OBJECTDIR}/Input_nomain.o: ${OBJECTDIR}/Input.o Input.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Input.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Input_nomain.o Input.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Input.o ${OBJECTDIR}/Input_nomain.o;\
	fi

${OBJECTDIR}/Lex_nomain.o: ${OBJECTDIR}/Lex.o Lex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Lex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lex_nomain.o Lex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Lex.o ${OBJECTDIR}/Lex_nomain.o;\
	fi

${OBJECTDIR}/Parameter_nomain.o: ${OBJECTDIR}/Parameter.o Parameter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Parameter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parameter_nomain.o Parameter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Parameter.o ${OBJECTDIR}/Parameter_nomain.o;\
	fi

${OBJECTDIR}/Parse_nomain.o: ${OBJECTDIR}/Parse.o Parse.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Parse.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Parse_nomain.o Parse.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Parse.o ${OBJECTDIR}/Parse_nomain.o;\
	fi

${OBJECTDIR}/Predicate_nomain.o: ${OBJECTDIR}/Predicate.o Predicate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Predicate.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Predicate_nomain.o Predicate.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Predicate.o ${OBJECTDIR}/Predicate_nomain.o;\
	fi

${OBJECTDIR}/Query_nomain.o: ${OBJECTDIR}/Query.o Query.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Query.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Query_nomain.o Query.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Query.o ${OBJECTDIR}/Query_nomain.o;\
	fi

${OBJECTDIR}/Rule_nomain.o: ${OBJECTDIR}/Rule.o Rule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Rule.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rule_nomain.o Rule.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Rule.o ${OBJECTDIR}/Rule_nomain.o;\
	fi

${OBJECTDIR}/RuleList_nomain.o: ${OBJECTDIR}/RuleList.o RuleList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/RuleList.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RuleList_nomain.o RuleList.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/RuleList.o ${OBJECTDIR}/RuleList_nomain.o;\
	fi

${OBJECTDIR}/State_nomain.o: ${OBJECTDIR}/State.o State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/State.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/State_nomain.o State.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/State.o ${OBJECTDIR}/State_nomain.o;\
	fi

${OBJECTDIR}/Table_nomain.o: ${OBJECTDIR}/Table.o Table.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Table.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Table_nomain.o Table.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Table.o ${OBJECTDIR}/Table_nomain.o;\
	fi

${OBJECTDIR}/Token_nomain.o: ${OBJECTDIR}/Token.o Token.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Token.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Token_nomain.o Token.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Token.o ${OBJECTDIR}/Token_nomain.o;\
	fi

${OBJECTDIR}/TokenType_nomain.o: ${OBJECTDIR}/TokenType.o TokenType.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TokenType.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TokenType_nomain.o TokenType.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TokenType.o ${OBJECTDIR}/TokenType_nomain.o;\
	fi

${OBJECTDIR}/Tuple_nomain.o: ${OBJECTDIR}/Tuple.o Tuple.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Tuple.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tuple_nomain.o Tuple.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Tuple.o ${OBJECTDIR}/Tuple_nomain.o;\
	fi

${OBJECTDIR}/Utils_nomain.o: ${OBJECTDIR}/Utils.o Utils.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Utils.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Utils_nomain.o Utils.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Utils.o ${OBJECTDIR}/Utils_nomain.o;\
	fi

${OBJECTDIR}/Vertex_nomain.o: ${OBJECTDIR}/Vertex.o Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Vertex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vertex_nomain.o Vertex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Vertex.o ${OBJECTDIR}/Vertex_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
