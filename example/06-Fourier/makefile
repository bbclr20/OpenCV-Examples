CXXFLAGS=g++

LIBS=-lopencv_core \
	 -lopencv_highgui \
	 -lopencv_imgproc \
	 -lopencv_imgcodecs

TARGETS=fourier.out

build: $(TARGETS)
fourier.out: fourier.cpp
	$(CXXFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -fr $(TARGETS)