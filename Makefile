build-original:
	g++ 1.cpp -o 1.o
build-modified:
	g++ 1-2.cpp -o modified.o
build-modified-o3:
	g++ 1-2.cpp -o modified-o3.o -O3
build-modified-flags:
	g++ 1-2.cpp -o modified-flags.o -O3 -fomit-frame-pointer -s -fno-elide-constructors -fno-rtti -fvisibility-inlines-hidden
