# Tipos de Kernel y sus diferencias

## Monolítico
### Descripción
En un kernel monolítico, todas las funciones del sistema operativo (como la gestión de archivos, protocolos de red, gestión de procesos) se ejecutan en el mismo espacio de memoria.
### Ventajas
- Alta eficiencia
- Alto rendimiento.
### Desventajas
- Fallos en el kernel pueden llevar a la caída de todo el sistema.

## Microkernel
### Descripción
Los microkernels ejecutan las funciones básicas del sistema operativo como la comunicación entre procesos y la gestión de la memoria. Las otras funciones se ejecutan en el espacio de usuario.
### Ventajas
- Mayor seguridad y estabilidad.
### Desventajas
- Puede ser menos eficiente debido a la comunicación entre el espacio de usuario y el kernel.

## Híbrido
### Descripción
Combinan elementos de kernels monolíticos y microkernels. Ejecutan algunos servicios en el espacio del kernel, mientras que otros se ejecutan en el espacio de usuario.
### Ventajas
- Balance entre rendimiento
- Flexibilidad.
### Desventajas
- Pueden heredar desventajas de ambos tipos.


# User vs Kernel Mode

## Modo Usuario (User Mode)
### Descripción
En este modo, las aplicaciones se ejecutan con un nivel de privilegio menor. No pueden acceder directamente a los recursos del hardware o a las áreas críticas del sistema operativo.
### Objetivo
Proporcionar un entorno seguro, previniendo que las aplicaciones afecten el funcionamiento del sistema en general.

## Modo Kernel (Kernel Mode)
### Descripción
El sistema operativo ejecuta sus tareas en este modo, con acceso completo al hardware y a todas las áreas de memoria.
### Objetivo
Permitir que el sistema operativo gestione eficientemente los recursos y ejecute las tareas críticas del sistema.

# Interrupciones vs Traps

## Interrupciones (Interrupts)
### Descripción
Señales generadas por el hardware para indicar al procesador que un evento necesita atención inmediata. Pueden ser generadas por hardware (como un dispositivo de entrada/salida) o por software.
### Uso
Permiten al procesador responder a eventos como la finalización de una operación de E/S.

## Traps
### Descripción
También conocidas como excepciones, son interrupciones generadas por el software cuando ocurre un error o una condición inusual.
### Uso
Permiten manejar errores o situaciones especiales en el código, como un error de división por cero o una llamada al sistema.
