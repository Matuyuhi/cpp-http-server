# Makefile

all:
	mkdir -p build
	cd build && cmake .. && make
run:
	build/cpp_http_server
clean:
	rm -rf build