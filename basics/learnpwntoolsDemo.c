#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define bufferSize 200

void spawnShell(){
	gid_t gid = getegid();
	setresgid(gid, gid, gid);
	system("/bin/sh -i");
}

void exploitme(){
	char name[bufferSize];
	puts("What is your name?\n");
	fflush(stdout);
	gets(name);
	printf("Hello! %s", name);
	fflush(stdout);
}

int main(){
	gid_t gid = getegid();
	setresgid(gid, gid, gid);
	exploitme();
	return 0;
}
