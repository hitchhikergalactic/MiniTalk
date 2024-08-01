Overview

Minitalk is a project that explores inter-process communication in C using Unix signals. The primary focus is on understanding and handling signals, converting characters to binary, and managing asynchronous communication between processes. This document provides an overview of the key concepts and implementations involved in Minitalk.
Signals

Signals are software interrupts used to notify a process of events. Common signals include SIGINT, SIGABRT, SIGQUIT, SIGUSR1, and SIGUSR2. When a signal is sent, the kernel can either ignore it, catch it using a handler function, or apply the default action.
Signal Handling

Two main approaches are used for handling signals:

    Signal() Function: An older method that lacks some protections and consistency across systems.
    Sigaction() Function: A more robust method that allows blocking of other signals and provides better control over signal handling.

Binary and Character Conversions 

The project involves converting characters to binary and vice versa, utilizing bitwise operators. This is crucial for sending and receiving data bit by bit through signals.
Example


For example, the character 'H' has a binary representation of 01001000. By right-shifting and extracting bits, this binary data can be transmitted as signals.
Implementation Overview
Client
 
The client sends data to the server by converting characters to binary and sending corresponding signals. It includes:

    Signal handlers to acknowledge responses from the server.
    A conversion function that sends each bit as a separate signal.



From top down, you would realise that when you line up the rightmost value
it will be 11110000, which is the binary value of -16.

From top down, you would realise that when you line up the rightmost value
it will be 01001000, which is the binary value of our H.It is this right-most 
value we will be saving everytime we shift

Server

The server receives the signals, reconstructs the binary data into characters, and displays them. It:

    Sets up signal handlers to process incoming bits.
    Converts binary data back into characters and handles message termination.

Key Considerations

    Asynchronous Communication: Handling signals requires careful synchronization to ensure data integrity.
    Error Handling: Includes checking for signal handling errors and managing unresponsive processes.
    Performance: Using usleep() for slight delays ensures the client does not overwhelm the server with signals.

FURTHER READING ON THE TOPIC

https://www.oracle.com/technical-resources/articles/it-infrastructure/dev-signal-handlers-studio.html
https://pubs.opengroup.org/onlinepubs/9699919799/functions/sigaction.html
http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html
https://linuxhint.com/c-sigaction-function-usage/
https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L12/Class.html
https://www.youtube.com/watch?v=L3XuR-iRysU&list=PLysdvSvCcUhbrU3HhGhfQVbhjnN9GXCq4&index=43
https://itecnote.com/tecnote/the-difference-between-sigaction-and-signal/
https://www-uxsup.csx.cam.ac.uk/courses/moved.Building/signals.pdf
