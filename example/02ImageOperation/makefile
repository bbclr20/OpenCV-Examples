CXXFLAGS=g++

LIBS=-lopencv_core \
	 -lopencv_highgui \
	 -lopencv_imgproc \
	 -lopencv_imgcodecs

TARGETS=image_operation.out

build: $(TARGETS)
image_operation.out: image_operation.cpp
	$(CXXFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -fr $(TARGETS)