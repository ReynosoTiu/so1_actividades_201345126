// Build:   gcc actividad_5.c -o actividad_5 -lpthread
// Run:     ./actividad_5

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

void * thread_function(void *arg) {
    printf("Thread en el proceso: %d, pid del hilo: %lu\n", getpid(), pthread_self());
}

int main() {
    pid_t pid;
    pthread_t thread_id;

    printf("Proceso inicial PID: %d\n", getpid());
    thread_function(&pid);


    pid = fork();
    if (pid == 0) { // Proceso hijo
        printf("Proceso hijo PID: %d, padre PID: %d\n", getpid(), getppid());

        pid_t child_pid = fork();
        thread_function(&child_pid);
        if (child_pid == 0) { // Hijo del hijo
            printf("Hijo del hijo PID: %d, padre PID: %d\n", getpid(), getppid());
        }
        // Esto lo ejecuta el proceso hijo y el hijo del hijo
        pthread_create(&thread_id, NULL, thread_function, NULL);
    } else {
        wait(NULL);
    }

    // El proceso padre original, el primer hijo y el hijo del hijo pasan por aca
    pid = fork();
    thread_function(&pid);
    if (pid == 0) { // Nuevo proceso hijo
        printf("Nuevo proceso hijo PID: %d, padre PID: %d\n", getpid(), getppid());
    } else {
        wait(NULL);
    }

    return 0;
}