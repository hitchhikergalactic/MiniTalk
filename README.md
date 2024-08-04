# MiniTalk

**MiniTalk** is a project that implements a communication system between a client and a server using UNIX signals. This project demonstrates how to send and receive messages encoded in binary through signals.

## How It Works

1. **Compiling the Program**

   To compile the program, follow these steps:

   ```bash
   git clone https://github.com/gjmacias/minitalk
   cd minitalk
   make
   ```

2. **Running the Server**

   In one terminal, start the server with:

   ```bash
   ./server
   ```

   This will print the server's PID, which is needed for the client to communicate with it. The message will look like this:

   ```
   SUCCESS!, Server is ready :D! The PID: *VWXYZ*
   ```

3. **Running the Client**

   In a **second** terminal, run the client, passing the server's PID and the message you want to send:

   ```bash
   ./client *VWXYZ* "I am a message that will be sent from the client to the server"
   ```

   Here, `*VWXYZ*` should be replaced with the PID of the server obtained from the previous step, and `"I am a message that will be sent from the client to the server"` is the message you want to send.

## How It Works

- **Server**:
  - **Initialization**: The server sets up `sigaction` to handle signals and specifies the `handler_sigusr1` function to process them.
  - **Active Waiting**: Uses `pause()` to sleep until signals are received.
  - **Signal Handling**: When a signal arrives, `handler_sigusr1` processes it and sends a `SIGUSR1` signal back to the client to confirm that it can send the next signal.

- **Client**:
  - **Encoding**: The client converts the message into a series of bits using the binary representation of each character.
  - **Sending Signals**: Sends each bit as a signal (`SIGUSR1` for 0 and `SIGUSR2` for 1) to the server.

## Functions Used

- **`sigaction`**: Configures the server to handle signals and defines the signal handler.
- **`kill`**: Sends signals to the client.
- **`getpid`**: Retrieves the server's PID.
- **`pause`**: Causes the server to wait until a signal is received.
- **`libft`**: Auxiliary functions such as `ft_memset` for initializing structures and `ft_strlen` for calculating string lengths.
  
TESTER
git clone https://github.com/ThibaudM13/minitalk-Tester.git
Preparation and execution

## 1. Edit the value of PATH_TO_CLIENT with your own client's path
## 2. Make your client and server program
## 3. Launch your server
## 4. Execute this script as below (By default the script launch the speed test on 1000 char)

./tester.sh <your server PID> [options]

Options:
  -m      Mandatory part
  -b      Execution of bonus part (All unicode)
  -[0-6]  Execution of special tests

  [Speed test]   Time to print 1 000 char 
$PATH_TO_CLIENT $p_id   0.02s user 0.03s system 9% cpu 0.584 total
 [Test 1]       Basic test 

 [Test 2]       Empty string

 [Test 3]       Sending big str with 20 000 char

 [Test 4]       Trying to crash your exhange Server-Client, sending str with 3 000 char (15 times) 
 [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [ 10 ] [ 11 ] [ 12 ] [ 13 ] [ 14 ] [ 15 ]
If all was corrrectly display on your server terminal: Perfect, well done! 💪

## About the Project

This project is part of my learning journey about inter-process communication and signal handling in UNIX. I am thoroughly enjoying this path and believe that sharing it can be even more rewarding. If you have ideas for improving this project or find ways to make it more efficient, please feel free to fork it and contribute! Any improvements or suggestions are greatly appreciated.

Thank you for your interest and happy coding!

---

https://www.oracle.com/technical-resources/articles/it-infrastructure/dev-signal-handlers-studio.html
https://pubs.opengroup.org/onlinepubs/9699919799/functions/sigaction.html
http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html
https://linuxhint.com/c-sigaction-function-usage/
https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L12/Class.html
https://www.youtube.com/watch?v=L3XuR-iRysU&list=PLysdvSvCcUhbrU3HhGhfQVbhjnN9GXCq4&index=43
https://itecnote.com/tecnote/the-difference-between-sigaction-and-signal/
https://www-uxsup.csx.cam.ac.uk/courses/moved.Building/signals.pdf
