CC=gcc
CXX=g++
RM=rm -f

SRCS=rsp.cpp Instance.cpp SolutionMedico.cpp PrintResult.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: rsp

rsp: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS) $(LDLIBS)

rsp.o: rsp.cpp Instance.hpp SolutionMedico.hpp PrintResult.hpp
Instance.o: Instance.hpp Instance.cpp
SolutionMedico.o: SolutionMedico.hpp SolutionMedico.cpp
PrintResult.o: PrintResult.hpp PrintResult.cpp

clean:
	$(RM) $(OBJS)
distclean: clean
	$(RM) main
