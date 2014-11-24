CC = g++
CFLAGS = -Wall -std=gnu++11 -I. $(shell pkg-config --libs --cflags glfw3)

core: src/example_scene.cc src/engine.cc src/main.cc
	${CC} ${CFLAGS} src/example_scene.cc src/engine.cc src/main.cc -o scrap

all: core
