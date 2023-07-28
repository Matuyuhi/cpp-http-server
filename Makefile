# Makefile

all:
	rm -rf build
	mkdir -p build
	cd build && cmake .. && make
run:
	build/cpp_http_server
clean:
	rm -rf build