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

    "H">>n
where n is the number of times we are shifting

***********************************
| 128| 64| 32| 16|  8|  4|  2|  1 |
|   0|  1|  0|  0|  1|  0|  0|  0 |
***********************************
|   0|  0|  0|  0|  0|  0|  0|  0 |  // shifting by 7 sums up to 0
|   0|  0|  0|  0|  0|  0|  0|  1 |  // shifting by 6 sums up to 1
|   0|  0|  0|  0|  0|  0|  1|  0 |  // shifting by 5 sums up to 2
|   0|  0|  0|  0|  0|  1|  0|  0 |  // shifting by 4 sums up to 4
|   0|  0|  0|  0|  1|  0|  0|  1 |  // shifting by 3 sums up to 9
|   0|  0|  0|  1|  0|  0|  1|  0 |  // shifting by 2 sums up to 18
|   0|  0|  1|  0|  0|  1|  0|  0 |  // shifting by 1 sums up to 36
|   0|  1|  0|  0|  1|  0|  0|  0 |  // shifting by 0 sums up to 72
***********************************

For example let's say we wanna convert -16 to binary
Step 1: We would find the binary value of +ve 16 -> 00010000
Step 2: We flip the digits to the opposite of what it was -> 11101111
Step 3: Then we would add 1. Note: 1 + 1 = 10, you will leave zero 
        and carry the one, while 1 + 1 + 1 = 11, leave 1 and carry 1
        therefore we will get 11110000

-128| 64| 32| 16|  8|  4|  2|  1|
   1|  1|  1|  1|  0|  0|  0|  0|
*********************************
The left most is is negative 128
Therefore, -128 + 64 + 32 + 16 = -16

Note: when right shifting you don't touch the bit at -128, and
you replace the void shifted with 1

***********************************
|-128| 64| 32| 16|  8|  4|  2|  1 |
|   1|  1|  1|  1|  0|  0|  0|  0 |
***********************************
|   1|  1|  1|  1|  1|  1|  1|  1 |  // shifting by 7 sums up to -1  (-128+64+32+16+8+4+2+1)
|   1|  1|  1|  1|  1|  1|  1|  1 |  // shifting by 6 sums up to -1  (-128+64+32+16+8+4+2+1)
|   1|  1|  1|  1|  1|  1|  1|  1 |  // shifting by 5 sums up to -1  (-128+64+32+16+8+4+2+1)
|   1|  1|  1|  1|  1|  1|  1|  1 |  // shifting by 4 sums up to -1  (-128+64+32+16+8+4+2+1)
|   1|  1|  1|  1|  1|  1|  1|  0 |  // shifting by 3 sums up to -2  (-128+64+32+16+8+4+2)
|   1|  1|  1|  1|  1|  1|  0|  0 |  // shifting by 2 sums up to -4  (-128+64+32+16+8+4)
|   1|  1|  1|  1|  1|  0|  0|  0 |  // shifting by 1 sums up to -8  (-128+64+32+16+8)
|   1|  1|  1|  1|  0|  0|  0|  0 |  // shifting by 0 sums up to -16 (-128+64+32+16)
***********************************

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
