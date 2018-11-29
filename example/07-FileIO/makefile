CXXFLAGS=g++

LIBS=-lopencv_core 

TARGETS=file.out

build: $(TARGETS)
file.out: file.cpp
	$(CXXFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -fr $(TARGETS)
