# Prueba de Procesos e hilos
## 1. Codigo en .c
```c
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

```
## 2. Creacion de Build.
```c
    gcc actividad_5.c -o actividad_5 -lpthread
```
## 3. Ejecucion de programa
```c
    ./actividad_5
```
## 4. Resultado
```text
Proceso inicial PID: 80106
Proceso hijo PID: 80107, padre PID: 80106
Hilo creado en el proceso: 80107, ID del hilo: 136825425360448
Nuevo proceso hijo PID: 80110, padre PID: 80107
Hijo del hijo PID: 80108, padre PID: 80107
Hilo creado en el proceso: 80108, ID del hilo: 136825425360448
Nuevo proceso hijo PID: 80112, padre PID: 80108
Nuevo proceso hijo PID: 80113, padre PID: 80106
```

## 5. ¿Cuántos procesos únicos son creados?
```text
Se crearon 6 procesos unicos.
Proceso 1 id:80106
Proceso 2 id:80107
Proceso 3 id:80110
Proceso 4 id:80108
Proceso 5 id:80112
Proceso 6 id:80113

```

## 6. ¿Cuántos hilos únicos son creados?
```text
Se crearon solamente 2 hilos.
Proceso id:80107 Hilo 1 id:136825425360448
Proceso id:80108 Hilo 1 id:136825425360448

```
