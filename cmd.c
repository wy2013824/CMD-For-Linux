#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PATH 1024

int main() {
    char cmd[256];
    char cwd[MAX_PATH];
	
	printf("GNU/Linux kubuntu 25.04\n");
    printf("type 'man' or 'help' to get more info.\n\n");

    while (1) {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s> ", cwd);
        } else {
            printf("ERROR> ");
        }
        
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) break;
        
        if (strcmp(cmd, "exit\n") == 0) break;
        
        if (strncmp(cmd, "cd ", 3) == 0) {
            char *path = cmd + 3;
            path[strcspn(path, "\n")] = 0;
            if (chdir(path) != 0) {
                perror("cd");
            }
            continue;
        }
        
        if (strncmp(cmd, "help ", 5) == 0) {
            system("bash -c help");
            continue;
        }

        if (strcmp(cmd, "cd\n") == 0) {
            char *home = getenv("HOME");
            if (home != NULL) {
                chdir(home);
            }
            continue;
        }

        if (strcmp(cmd, "help\n") == 0) {
            system("bash -c help");
            continue;
        }
        
        system(cmd);
    }
    
    return 0;
}
