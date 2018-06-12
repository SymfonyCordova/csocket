#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
31) SIGSYS

*/

void isMember(const sigset_t *set, const int signum, const char *str){
	int ret = sigismember(set, signum);
	if(ret == -1){
		perror("sigismember error");
		exit(1);
	}
	
	printf("%s : %d\n", str, ret); 
}

int main(void){
	sigset_t set, myset;
	int ret, i;
	int arr1[31] = { SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGTRAP, SIGABRT, SIGBUS, SIGFPE, SIGKILL, SIGUSR1, SIGSEGV, SIGUSR2, SIGPIPE,
				 SIGALRM, SIGTERM, SIGSTKFLT, SIGCHLD, SIGCONT, SIGSTOP, SIGTSTP, SIGTTIN, SIGTTOU, SIGURG, SIGXCPU, SIGXFSZ,SIGVTALRM, 
				 SIGPROF , SIGWINCH, SIGIO, SIGPWR, SIGSYS};	

	char* arr2[31] = { "SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGTRAP", "SIGABRT", "SIGBUS", "SIGFPE", "SIGKILL", "SIGUSR1", "SIGSEGV", "SIGUSR2", "SIGPIPE",
				 "SIGALRM", "SIGTERM", "SIGSTKFLT", "SIGCHLD", "SIGCONT", "SIGSTOP", "SIGTSTP", "SIGTTIN", "SIGTTOU", "SIGURG", "SIGXCPU", "SIGXFSZ", "SIGVTALRM", 
				 "SIGPROF" , "SIGWINCH", "SIGIO", "SIGPWR", "SIGSYS"};	
	
	ret = sigemptyset(&set);
	if(ret == -1){
		perror("sigemptyset error");
		exit(1);
	}

	ret = sigpending(&set);
	if(ret == -1){
		perror("sigpending error");
		exit(1);
	}
	
	for(i = 0; i < 31; ++i){
		isMember(&set, arr1[i], arr2[i]);
	}
	return 0;
}
