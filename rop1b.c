#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void shellnotcalled()
{
	printf("This is your shell, can you call it?");
	setuid(0);
	setgid(0);	
	system("/bin/bash");
}

void rop1()
{
	printf("ROP 1!\n");
}

void rop2()
{
	printf("ROP 2!\n");
}

void rop3()
{
	printf("ROP 3!\n");
}

void vulnerable(char* string)
{
	char buffer[100];
	strcpy(buffer, string);
}

int main(int argc, char** argv)
{
	vulnerable(argv[1]);
	return 0;
}
