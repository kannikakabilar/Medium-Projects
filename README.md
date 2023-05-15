# Medium-Projects
This repo contains a collection of medium-sized projects in Python, C, MySQL, JavaScript-React, and JavaScript-Angular.
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
## KanBatchOS - Kan Batch OS Model
The Kan Batch OS Model is a Batch Operating System Simulator. Currently, this model supports running batches of Python, C, and, Java program files but it can be easily extended to support the execution of other program files. This simulator is designed to run in a Linux hosted environment as it uses 'ls' command to collect the list of programming files to execute. <br />

- How it works <br />
Batch OS executes jobs in batches, so this model reflects the design by grouping files of the same programming language, and executing the collected files all at once.  ie: All Python files will be collected and executed together, then all C files will be collected and executed together and so on. Batch OS does not support interactive programs that require user's input during execution. An image of the model being executed is shown below.

<p align="center">
  <img alt="Light" src="osp1.png" width="90%">
</p>

- How to Run <br />
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
![Quote](https://raw.githubusercontent.com/kannikakabilar/Medium-Projects/main/SynchronizeSequence/Screen%20Shot%202022-04-15%20at%207.46.52%20PM.png)

## CloudServer 
Cloud Server is a software program designed to synchronize process execution efficiently (simulating a cloud environment). The program utilizes CPU scheduling algorithms in a multi-level feedback queue which allows it order processes to execute with the least amount of response and wait time. <br />

- How it works <br />
The program uses a PCB struct to store information about the process. In order to execute it with the other sets of jobs, a node struct is created to point at the job. This node job is then inserted into the ready queue, which is built using a doubly linked list. The jobs are inserted into the multi-level feedback queue based on their defined priority. When each of theses queues are sent for execution, a thread is created for each job in the queue to execute simultaneously. Mutex locks are used to protect the critical section, preventing race conditions while accessing shared resources. Once job has completed its cpu time and its execution, it is removed from the queue, if it still hasn't completed its execution, it will re-inserted into the queue with its updated attributes. 

- How to Run
```md
> cd <path to directory of CloudServer>
> make
> ./cloud
```
![Quote](https://github.com/kannikakabilar/Medium-Projects/blob/main/CloudServer/cloud_demo1.png)
![Quote](https://github.com/kannikakabilar/Medium-Projects/blob/main/CloudServer/cloud_demo2.png)

## ChatGPT-React
A ChatGPT application built using React for frontend and NodeJS with Express framework for backend.
- The server communicates with the advanced GPT3 model API
- Elegant and responsive User Interface that enhances the ChatGPT app
- server.js can be modified to chat with any of OpenAI's trained models with a wide range of frequencies

## 4KPlace - Product Catalog - Angular15
A product catalog webpage coded using Angular15 for its frontend framework. 
- How to run
Open terminal and navigate (cd) to where the project is cloned/downloaded
```md
> npm install --legacy-peer-deps
> ng serve
```
![Quote](https://github.com/kannikakabilar/Medium-Projects/blob/main/4KPlace-ProductCatalog/Screen%20Shot%202023-02-26%20at%205.20.48%20PM.png)

## NodeApp
An application to experiment node.js and expressjs functionalities
- How to run
Open terminal and navigate (cd) to where the project is cloned/downloaded
```md
> npm install --legacy-peer-deps
> node index.js (or any other *.js file name)
```
