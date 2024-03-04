# cliente1.sh
#!/bin/bash

# Se defile el nombre del pipeFIFO
PIPE=/tmp/chat_fifo

# Si no existe se crea el FIFO
[ -p $PIPE ] || mkfifo $PIPE


while true; do
    read mensaje1
    echo "cliente1: $mensaje1" >> $PIPE 
donew
