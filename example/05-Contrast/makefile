CXXFLAGS=g++

LIBS=-lopencv_core \
	 -lopencv_highgui \
	 -lopencv_imgproc \
	 -lopencv_imgcodecs

TARGETS=contrast.out

build: $(TARGETS)
contrast.out: contrast.cpp
	$(CXXFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -fr $(TARGETS)