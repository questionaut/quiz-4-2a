#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>


// include additional necessary headers

using namespace std;

// typedef struct {sem_t semQ; sem_t semR; int cnt;} passMeType;
sem_t semQuery;
sem_t semResponse;
int count;



void *query(void* arg) {
    // Should print: the print number (starting from 0), "SYN", and the three dots "..."
    for (int i = 0; i < count; i++) {
        sem_wait(&semQuery);
        cout << "[" << i << "] SYN ... " ;
        sem_post(&semResponse);
    }
    

    return NULL;
}

void *response(void* arg) {
    // Should print "ACK"
    for (int i = 0; i < count; i++) {
        sem_wait(&semResponse);
        cout << "ACK" << endl;
        sem_post(&semQuery);   
    }

    return NULL;

}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./handshake <count>\n");
        exit(1);
    }

    count = stoi(argv[1]);
    sem_init(&semQuery, 0, 1);
    sem_init(&semResponse, 0, 0);

    pthread_t que;
    pthread_t res;

    if (pthread_create(&que, NULL, query, NULL)) {
        perror("problem creating syn thread");
        exit(0);
    }
    if (pthread_create(&res, NULL, response, NULL) != 0) {
        perror("problem creating ack thread");
        exit(0);
    }

   
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