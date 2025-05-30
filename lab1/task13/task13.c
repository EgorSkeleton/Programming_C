#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig){
	char *signal_name;
	
	switch(sig){
		case SIGABRT: signal_name = "SIGABRT"; break;
		case SIGFPE:  signal_name = "SIGFPE";  break;
        case SIGILL:  signal_name = "SIGILL";  break;
        case SIGINT:  signal_name = "SIGINT";  break;
        case SIGSEGV: signal_name = "SIGSEGV"; break;
        case SIGTERM: signal_name = "SIGTERM"; break;
        default: signal_name = "UNKNOWN"; break;
	}
	
	printf("recieved signal: %s (%d)\n", signal_name, sig);
}

void setup_signal_handlers(){
	signal(SIGABRT, handler);
	signal(SIGFPE, handler);
	signal(SIGILL, handler);
	signal(SIGINT, handler);
	signal(SIGSEGV, handler);
	signal(SIGTERM, handler);
}

void menu(){
	printf("Choose signal\n");
	printf("1. SIGABRT\n");
    printf("2. SIGFPE\n");
    printf("3. SIGILL\n");
    printf("4. SIGINT\n");
    printf("5. SIGSEGV\n");
    printf("6. SIGTERM\n");
    printf("0. Exit\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice){
    	case 1: raise(SIGABRT); break;
    	case 2: raise(SIGFPE); break;
    	case 3: raise(SIGILL); break;
    	case 4: raise(SIGINT);  break;
        case 5: {
            int *ptr = NULL;
            *ptr = 1;
            break;
        }
        case 6: raise(SIGTERM); break;
        case 0: exit(0); break;
        default: printf("Input error\n"); break;
	}
}

int main() {
	setup_signal_handlers();
	while(1){
		menu();
	}
	return 0;
}
