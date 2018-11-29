CXXFLAGS=g++

LIBS=-lopencv_core \
	 -lopencv_highgui \
	 -lopencv_imgproc \
	 -lopencv_imgcodecs

TARGETS=eroding_dilating.out

build: $(TARGETS)
eroding_dilating.out: eroding_dilating.cpp
	$(CXXFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -fr $(TARGETS)