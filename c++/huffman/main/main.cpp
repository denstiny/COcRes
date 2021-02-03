/**
 * main.cpp 
 */
#include <iostream>
#include <cstdio>
#include "../include/huffman.h"
using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage:\n\t huffmancoding inputfile outputfile\n");
		std::cout << argc << std::endl;
        exit(1);
    }

    if(0 == strcmp("-c", argv[1]))
    {
        Huffman h(argv[2], argv[3]);
        h.compress();
    }
    else if(0 == strcmp("-x", argv[1]))
    {
        Huffman h(argv[2], argv[3]);
        h.decompress();
    }
    else
    {
        printf("Usage:\n\t unkonwn command\n");
    }
    return 0;
}
