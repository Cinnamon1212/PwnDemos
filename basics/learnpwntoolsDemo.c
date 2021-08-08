#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int bufferSize = 128;

void spawnShell(){
	setPrivs();
	system("/bin/sh -i");
}

void setPrivs(){
	gid_t gid = getegid();
	setresgid(gid, gid, gid);
}

void exploitme(){
	char name[bufferSize];
	puts("What is your name? ");
	fflush(stdout);
	gets(name);
	puts(name);
	fflush(stdout);
}

int main(int argc, char **argv){
	puts("WELCOME TO PWNTOOLS DEMO #1\n");
	setPrivs();
	exploitme();
	return 0;
}
