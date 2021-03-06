CC = g++
CFLAGS = -g -Wall -std=c++11
SRCS = $(shell find . -name "*.cpp")
PROG = ${SRCS:.cpp=.bin}

OPENCV = `pkg-config opencv --cflags --libs`
LIBS = $(OPENCV)

binaries: $(PROG)

$(PROG):$(SRCS)
	@$(CC) $(CFLAGS) -o $@ $< $(LIBS)
