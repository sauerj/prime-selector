#include <stdio.h>
#include <unistd.h>

int main (int argc, char** argv) {
	if (argc < 2) {
		printf ("usage: primeselect intel|nvidia\n");
		return 0;
	}

	if (strcmp (argv[1], "intel")==0) {
		printf("activate Intel GPU\n");
		execl ("/usr/bin/prime-select", "prime-select", "intel", NULL);
		return 0;
	}
	else if (strcmp(argv[1], "nvidia")==0) {
		printf("activate Nvidia GPU\n");
		execl ("/usr/bin/prime-select", "prime-select", "nvidia", NULL);
	    return 0;
	}
	else {
		printf ("wrong argument:\nusage: primeselect intel|nvidia\n");
		return 0;
	}
	return 0;
}
