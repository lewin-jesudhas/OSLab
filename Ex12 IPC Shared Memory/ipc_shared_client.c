#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

int main() {
    key_t key = ftok("shmfile", 65); // Generate unique key (same as server)

    int shmid = shmget(key, 1024, 0666); // Access shared memory segment created by server

    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    char *str = (char *) shmat(shmid, (void *)0, 0); // Attach to shared memory
    if (str == (char *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Read data from shared memory
    printf("Client reads: %s\n", str);

    shmdt(str); // Detach from shared memory

    return 0;
}