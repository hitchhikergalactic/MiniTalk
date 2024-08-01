42 Minitalk Explained

    This document is open to discussion and corrections for the purpose of improving accuracy and clarity.

signals

To comprehend the implementation of Minitalk, it is necessary to have a fundamental understanding of signals and sigaction, as well as the process of converting characters to binary and vice versa.

Signals are software interruptions that are utilized to interrupt a running process to execute another action. These interruptions are often encountered in various situations, such as bus errors or segfaults, and when attempting to terminate a program with the ctrl+c command.

There are different types of signals, including SIGINT, SIGABRT, SIGQUIT, SIGUSR1, and SIGUSR2. A comprehensive list of signals can be found at https://www-uxsup.csx.cam.ac.uk/courses/moved.Building/signals.pdf. When a signal is activated, the process sends a signal to the kernel, which then utilizes the sig_handler() function to perform one of three possible actions: ignore, catch, or default.

If a signal is ignored, it means that the process has no response to the interruption, although it should be noted that certain signals cannot be ignored, such as SIGKILL and SIGSTOP. If a signal is caught, the process registers a function with the kernel to handle the interruption. If a signal executes its default behavior, it indicates that the process is using the SIG_DFL signal.

// SIG_IGN: Ignored
#include <unistd.h>
#include <signal.h>

int main(void)
{
   struct sigaction sa;
  
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_RESTART | SA_SIGINFO;
   sa.sa_handler = SIG_IGN;
   sigaction(SIGINT, &sa, NULL);
   while (1)
      sleep(1);
   return (0);
}

// Caught
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_handler(int signum, siginfo_t* info, void* context)
{
   (void)context;
   (void)info;
   (void)signum;
   printf("\nSignal handler function called %d\n", signum);
}

int main(void)
{
   struct sigaction sa;
  
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_RESTART | SA_SIGINFO;
   sa.sa_sigaction = sig_handler;
   sigaction(SIGINT, &sa, NULL);
   while (1)
     sleep(1);
   return (0);
}

// SIG_DFL: Default
#include <unistd.h>
#include <signal.h>

int main(void)
{
   struct sigaction sa;
  
   sigemptyset(&sa.sa_mask);
   sa.sa_flags = SA_RESTART | SA_SIGINFO;
   sa.sa_handler = SIG_DFL;
   sigaction(SIGINT, &sa, NULL);
   while (1)
     sleep(1);
   return (0);
}

I am sure you are wondering what the hell is this sigaction syntax because we have not made mention of it anywhere. The thing is sigaction is an alternative and more modern way of handling signals. We can rewrite the functions we have written above for ignored, default, and caught using the signal instead of sigaction.

#include <unistd.h>
#include <signal.h>

int main(void)
{
   // Default action
   signal(SIGINT, SIG_DFL);
   while (1)
      sleep(1);
   return (0);
}


#include <unistd.h>
#include <signal.h>

int main(void)
{
  // IGNORED
   signal(SIGINT, SIG_IGN);
   while (1)
      sleep(1);
   return (0);
}

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_handler(int signum)
{
  printf("\nSignal handler function called %d\n", signum);
}

int main(void)
{
   signal(SIGINT, sig_handler);
   while (1)
      sleep(1);
   return (0);
}

Yeah, I know what you’re thinking and I agree with you — using signal over sigaction is syntactically more pleasing. Now I think it’s okay to talk about the benefit of preferring that syntactic headache.

    The signal() the interface has antiquity in its favor. Nevertheless, it has several undesirable characteristics that sigaction() avoids - unless you use the flags explicitly added to sigaction() to allow it to faithfully simulate the old signal() behavior.

    The signal() the function does not (necessarily) block other signals from arriving while the current handler is executing; sigaction() can block other signals until the current handler returns.

    The signal() function (usually) resets the signal action back to SIG_DFL (default) for almost all signals. This means that the signal() the handler must reinstall itself as its first action. It also opens up a window of vulnerability between the time when the signal is detected and the handler is reinstalled during which if a second instance of the signal arrives, the default behavior (usually terminate, sometimes with prejudice - aka core dump) occurs.

    The exact behavior of signal() varies between systems — and the standards permit those variations. https://itecnote.com/tecnote/the-difference-between-sigaction-and-signal/

Now that we know theirs no escaping the sigaction, then I think we should talk about the syntax.

    The sa_mask field indicates any signals that should be blocked while the signal handler is being executed. The sa_flags field determines a number of different things, but the important ones are whether we get the extended information (SA_SIGINFO ) and whether system calls that were interrupted by the signal are automatically restarted (SA_RESTART), The alternative is that the interrupted system calls will fail, so restarting them is obviously a better approach. https://www.oracle.com/technical-resources/articles/it-infrastructure/dev-signal-handlers-studio.html

Also, we can use the sa_handler and sa_sigaction properties of the sigaction interchangeably to handle the sig_handler()function. The sigaction function handler has a prototype that provides the signal number, information about the signal delivery, and information about the thread context

void  handle_prof_signal(int signal_number, siginfo_t * info, void * context)

By now, I think if you look back at some of the functions we wrote earlier, you should have more clarity.
Binary and Character Conversions Using Bitwise Operators

So that we don’t detour far too much, I won’t be going too deep into bitwise operators, I’ll only focus on the operations we are performing during our conversions.

I am going to use two characters for my explanation “H” and “🌍”. It should be noted that some Unicode characters like “H” are only 1 byte (8 bits) while others can be as many as 4 bytes (32 bits).

H — has a binary code of 01001000 and an ASCII code of 72, for us to loop over these bits, we will need to use the right-shift bitwise operator.

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

From top down, you would realise that when you line up the rightmost value
it will be 01001000, which is the binary value of our H.It is this right-most 
value we will be saving everytime we shift

Also, we need to understand how to handle negative numbers because some of our Unicode characters are going to be negative. The leftmost value of a binary serves as an indicator of a negative number.

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

Now, here is the code of the above illustration

#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h> 

char bin_to_char(int** ptr)
{
    char c = 0;
    int byte_idx = 0;
    int bit_idx;
    
    while (ptr[byte_idx] != NULL) // While there are more bytes
    {
        c = 0; // Reset character for each byte
        bit_idx = 0;

        while (bit_idx < 8) // Process each bit in the byte
        {
            if (ptr[byte_idx][bit_idx] == 1)
                c = (c << 1) | 1;
            else
                c <<= 1;
            bit_idx++;
        }
        printf("Character: %c\n", c); // Display the reconstructed character
        byte_idx++;
    }
    return c;
}

int** char_to_bin(char* str)
{
    int** ptr;
    int byte_index = 0;
    int bit_index;
    int i;

    // Find the length of the string
    while (str[byte_index] != '\0')
        byte_index++;
    
    // Allocate memory for the array of pointers
    ptr = (int**)calloc(byte_index + 1, sizeof(int*));
    if (!ptr) return NULL;
    
    byte_index = 0;
    while (str[byte_index] != '\0') // While there are more characters
    {
        ptr[byte_index] = (int*)calloc(8, sizeof(int));
        if (!ptr[byte_index])
        {
            // Free previously allocated memory on failure
            int j = 0;
            while (j < byte_index)
            {
                free(ptr[j]);
                j++;
            }
            free(ptr);
            return NULL;
        }

        bit_index = 7;
        i = 0;
        while (bit_index >= 0) // Convert each character to binary
        {
            ptr[byte_index][i++] = (str[byte_index] >> bit_index) & 1;
            printf("%d -> %d\n",
                str[byte_index] >> bit_index,
                (str[byte_index] >> bit_index) & 1);
            bit_index--;
        }
        printf(" : ");
        byte_index++;
    }
    
    ptr[byte_index] = NULL;
    return ptr;
}

int main(void) {
   // char str[5] = "🌍"; // -16:-97:-116:-115 or 11110000 : 10011111 : 10001100 : 10001101
   char str[2] = "H"; // 72 01001000
   int** ptr;
  
   ptr = char_to_bin(str);
   bin_to_char(ptr);
   return (0);
}

What we need is to make our application consist of two processes, one that waits to read each character — the server, and the other that will send the character to the server — the client. The key issue is that the second process will need to somehow signal the first for every new character encountered.

A process can send a signal with the kill or raisesystem call.

int kill(pidt pid, int signum);
int raise(int signum);

We will be using the killsystem call. The first argument is the process ID of the intended recipient of the signal. For the second, you usually use a predefined constant like SIGINT. Receiving a signal is a bit tricky. You see, the recipient process has no idea when the signal will come in. It'll be minding its own business, computing whatever it computes when it is suddenly interrupted by the arrival of this signal. This kind of communication is called asynchronous, meaning that there's no logic as to when the input comes.

Now, we have enough pieces of the puzzle to implement our Minitalk. And I will only be implementing this with pseudocode, there are two pseudocode for each implementation, such that if you miss a logic in the first, you can gain clarity in the second.

// CLIENT.C file

/** global static int variable. it will help us note 
*   when we stopped receiving signals
*/

void sig_handler(int signum, siginfo_t* info, void* context)
{
  /** 
     *  create a variable static int i to count the numbers of bit read
     *  void the args you are not using
     *
     *  change the global varaible to 1
     *  if signum == SIGUSR2 
     *     increment i
     *  else if signum == SIGUSR1 
      *    print the number of bytes recieved (NB: 8 bits = 1 byte)
     */
}

int char_to_bin(char c, int pid)
{
  /** 
     *  VARIABLES
     *  
     *  create a variable int itr
     *  int bit_index to loop over each byte
     *
     *  initialise bit_index to 7 ie 0 -> 7 which will make 8 bits
     *  create a while loop to loop bit by bit by decrementing from 7 to 0
     * while(bit_idx >= 0)
     *{
          // initialize itr back to zero
          // conversion
          if ((c >> bit_index) & 1)
              kill(pid, SIGUSR1);
          else
              kill(pid, SIGUSR2);
          while (g_receiver == 0)
          {
             if (itr == 50) // wait for response after count of 50 (any number)
             {
                //print no response from server here and exit
             }
             // increment itr by 1
             usleep(100); // gives enough time for each signal to be processed
          }
          // re-initialize g_receiver back to zero and decrement bit_index by 1
         }
         return (0);
     */
}

int main(int argc, char* argv[])
{
  /** 
   *  VARIABLES
   *  create a struct for our sigaction
   *  create a variable for each byte
   *  then variable for the process identifier
   *
   *  SIGACTION
   *  Check if the right number of argument is being passed
   *  convert the servers pid argument from string to number
          and save it to the process identifier variable
   *  empty the signal numbers to prevent error 
   *  -> u can use the sigemptyset. some people also use the memset func
   *  set the appropraite flags for sigaction
   *  also set the sig_handler func
   *  call the sigaction function twice: with SIGUSR1 and SIGUSR2 respectively
   *  you can handle the error for the function call,
   *  where -1 means an error occurred
   *  Handle each character of the string by looping over
   *  and converting to binary using a function with a prototype of
   *  int char_to_bin(char c, int pid) // note: c -> argv[2][byte_index++]
   *  then outside the loop call the conversion function again but
   *  this time pass '\0' as char. This is important in preparing 
   *  the server for new feed of strings 
   */
}


// ALT PSUEDOCODE (same as above)

STATIC int g_receiver = 0

FUNCTION sig_handler(int signum, siginfo_t *info, void *context)
    STATIC int i = 0

    SET g_receiver = 1
    IF signum IS SIGUSR2 THEN
        INCREMENT i
    ELSE IF signum IS SIGUSR1 THEN
        PRINT "Number of bytes received: " AND (i / 8)
    END IF
END FUNCTION

FUNCTION ft_char_to_bin(char c, int pid)
    FOR bit_index FROM 7 TO 0 DO
        IF ((c >> bit_index) AND 1) IS TRUE THEN
            SEND SIGUSR1 TO pid
        ELSE
            SEND SIGUSR2 TO pid
        END IF

        DECLARE itr = 0
        WHILE g_receiver IS 0 DO
            IF itr EQUALS 50 THEN
                PRINT "No response from server."
                EXIT WITH ERROR
            END IF
            INCREMENT itr
            WAIT FOR 100 microseconds
        END WHILE
        SET g_receiver TO 0
    END FOR
END FUNCTION

FUNCTION main(int argc, char *argv[])
    DECLARE sigaction sa
    DECLARE int byte_index = 0
    DECLARE int pid

    IF argc NOT EQUALS 3 THEN
        PRINT "You need to pass 2 args but u passed " AND (argc - 1)
        RETURN 1
    END IF

    SET pid TO atoi(argv[1])
    SET signal handlers FOR SIGUSR1 AND SIGUSR2

    WHILE argv[2][byte_index] IS NOT NULL DO
        CALL ft_char_to_bin(argv[2][byte_index], pid)
        INCREMENT byte_index
    END WHILE

    CALL ft_char_to_bin('\0', pid)  // Send termination character

    RETURN 0
END FUNCTION

END

void bin_to_char(int signum, char* c)
{
/**
 * if (signum == SIGUSR1) *c = (*c << 1) | 1;
 * else if (signum == SIGUSR2) *c <<= 1;
*/
}

void sig_handler(int signum, siginfo_t* info, void* context)
{
  /**
  * create static int variable for pid and i and static char for c
  * void unused arg
  * set the details of the pid you are receiving from to the pid by using
  * info->pid
  * send the signal number and address of c to the bin_to_char function
  * if (++i == 8) // for every 8 bit read c
     {
      initialize i to 0
      if (!c) // this if block prepares the server for new feed of strings
      {
         kill(pid, SIGUSR1);
         // initialize pid to zero, so that you can handle multiple terminals
         // return
      }
      // since we have read 8 bits we can now read c and then initalise it back
      // back to null
     }
     kill(pid, SIGUSR2);
  */
}

int main(void)
{
/** 
   *  VARIABLES
   *  create a struct for our sigaction
   * 
   *  print the server pid using getpid()
   *  SIGACTION
   *  -> u can use the sigemptyset. some people also use the memset func
   *  set the appropraite flags for sigaction
   *  also set the sig_handler func
   *  call the sigaction function twice: with SIGUSR1 and SIGUSR2 respectively
   *  you can handle the error for the function call,
   *  create a while loop to wait for signals while(1) pause();
   */
 return (0);
}


// ALT PSUEDOCODE (Same as above)
FUNCTION ft_bin_to_char(signum, *char c)
    IF signum IS SIGUSR1 THEN
        SET *c = (*c << 1) OR 1
    ELSE IF signum IS SIGUSR2 THEN
        SET *c = *c << 1
    END IF
END FUNCTION

FUNCTION sig_handler(int signum, siginfo_t *info, void *context)
    STATIC int pid = 0
    STATIC char c = 0
    STATIC int i = 0

    IF pid IS 0 THEN
        SET pid = info->si_pid
    END IF

    CALL ft_bin_to_char(signum, &c)

    INCREMENT i

    IF i EQUALS 8 THEN
        RESET i

        IF c EQUALS NULL CHARACTER THEN
            SEND SIGUSR1 TO pid  // Acknowledge end of message
            RESET pid
            RETURN
        END IF

        PRINT c TO STDOUT
        RESET c
    END IF

    SEND SIGUSR2 TO pid  // Acknowledge bit received
END FUNCTION

FUNCTION main()
    DECLARE sigaction sa

    PRINT "Server PID: " AND getpid()
    SET sa.sa_flags TO SA_RESTART | SA_SIGINFO
    SET sa.sa_sigaction TO sig_handler

    SET signal handlers FOR SIGUSR1 AND SIGUSR2

    LOOP FOREVER
        CALL pause()
    END LOOP
END FUNCTION

END

FURTHER READING ON THE TOPIC

https://www.oracle.com/technical-resources/articles/it-infrastructure/dev-signal-handlers-studio.html
https://pubs.opengroup.org/onlinepubs/9699919799/functions/sigaction.html
http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html
https://linuxhint.com/c-sigaction-function-usage/
https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L12/Class.html
https://www.youtube.com/watch?v=L3XuR-iRysU&list=PLysdvSvCcUhbrU3HhGhfQVbhjnN9GXCq4&index=43
https://itecnote.com/tecnote/the-difference-between-sigaction-and-signal/
https://www-uxsup.csx.cam.ac.uk/courses/moved.Building/signals.pdf
