#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>


// include additional necessary headers

using namespace std;

void query(/*add necessary parameters*/) {
    // Should print: the print number (starting from 0), "SYN", and the three dots "..."
}

void response(/*add necessary parameters*/) {
    // Should print "ACK"
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./handshake <count>\n");
        exit(1);
    }

    // Steps to follow:
    // 1. Get the "count" from cmd args
    int count = stoi(argv[1]);
    // 2. Create necessary synchronization primitive(s)
    sem_t semResponse;
    sem_t semQuery;

    sem_init(&semResponse, 0, 1);
    sem_init(&semQuery, 0, 1);
    // 3. Create two threads, one for "SYN" and the other for "ACK"
    
    // 4. Provide the threads with necessary args
    // 5. Update the "query" and "response" functions to synchronize the output
   
    return 0;
}

/**
 * PSEUDOCODE GIVEN IN CLASS
 * 
 * ADVICE IS TO READ SEMAPHORE READING PRIOR TO STARTING
 * 
 * main {
 * count = argv[1]
 * create two semaphores
 *      one for response
 *      one for query
 * create two threads [semaphores must be passed with the threats]
 *      thread (query...)
 *      thread (response...)
 * Wait on the threads using join()
 * Destroy semaphores
 * } END MAIN
 * 
 * query() {
 * put in a loop based off of count
 *      sem_wait(response_sem) [can read about it on "Semaphores" reading on Canvas]
 *      print out text
 *      sem_post(query_sem)
 * } END QUERY
 * 
 * response() {
 * sem_wait(response_sem)
 * sem_post(query_sem)
 * count--
 * } END RESPONSE
 * 
*/