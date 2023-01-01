# Medium-Projects
This repo contains a collection of medium-sized projects in Python, C, and MySQL.
<br />
<br />
## Public Transit Transportation Database System
A database system for a transit service that contains a table for passengers, routes, stops, and vehicles. MySQL is used to design the SQL queries.
<br />
<br />
## Hangman
A hangman game programmed in python using pygame. The game contains visual components to keep the users engaged.
- To run the file
Make sure pygame is installed and run hangman.py <br />
```md
> pip install pygame
> python3 hangman.py
```
## KanBatchOS 
The Kan Batch OS Model is a Batch Operating System Simulator. Currently, this model supports running batches of Python, C, and, Java program files but it can be easily extended to support the execution of other program files. This simulator is designed to run in a Linux hosted environment as it uses 'ls' command to collect the list of programming files to execute. <br />

- How to Run
Place your Python, Java, and, C programs in the Jobs directory <br />
Navigate to kanbatchos directory (ie: cd kanbatchos) and then execute below <br />
```md
> gcc -o kan kanbatchos.c
> ./kan 
```

## SecureFileSender 
SecureFileSender is a software that allows users to safely send files to different computers. The program utilizes private and public keys from the RSA algorithm to encrypt and decrypt the transferring files. The program also uses python sockets to transfer the files from sender to receiver.

- Requirements
Python 3.8 must be installed. The program will also utilize the following libraries.
```md
> pip3 install cryptography
> pip3 install tqdm
```
## SynchronizeSequence
The Synchronize Sequence program utilizes the multiple cores of a device's processor effectively to execute functions synchronously. The program makes use of fork system call to run processes concurrently and share results through a pipe file descriptor. This program can be used to execute memory occupying and cpu bound processes simultaneously allowing it to reduce its execution time. The program can also be easily modified by adding execl() system call to execute another program synchronously while calculating the order of the sequence. 

- How to Run
Navigate to the repository where the program is located
```md
> make
> ./syncseq
```
Execute the above commands in terminal and enter user inputs as prompted. The below image illustrates a demonstration. <br />
![Quote](https://github.com/kannikakabilar/SynchronizeSequence/blob/main/Screen%20Shot%202022-04-15%20at%207.46.52%20PM.png)

## CloudServer 
Cloud Server is a software program designed to synchronize process execution efficiently (simulating a cloud environment). The program utilizes CPU scheduling algorithms in a multi-level feedback queue which allows it order processes to execute with the least amount of response and wait time. <br />

- How to Run
```md
> cd <path to directory of CloudServer>
> make
> ./cloud
```
![Quote](https://github.com/kannikakabilar/CloudServer/blob/main/cloud_demo1.png)
![Quote](https://github.com/kannikakabilar/CloudServer/blob/main/cloud_demo2.png)
