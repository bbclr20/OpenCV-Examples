CXXFLAGS=g++

LIBS=-lopencv_core \
	 -lopencv_highgui \
	 -lopencv_imgcodecs

TARGETS=hello.out

build: $(TARGETS)
hello.out: hello.cpp
	$(CXXFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -fr $(TARGETS)