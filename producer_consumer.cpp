#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

const int BUFFERSIZE = 10;
int buffer[BUFFERSIZE]{-1}, index = 0, nop = 0;
pthread_mutex_t mutex;
sem_t full_slots, empty_slots;

void* produce(void*) {
        sleep(1);
        sem_wait(&empty_slots);
        pthread_mutex_lock(&mutex);
        cout<<"______________________________"<<endl;
        cout<<"Producing an item..."<<endl;
        sleep(0.5);
        int item = rand()%1000;
        buffer[index++] = item;
        cout<<"Produced item with id : "<<item<<endl;
        nop--;
        pthread_mutex_unlock(&mutex);
        sem_post(&full_slots);    
}

void* consume(void*) {
        sleep(1);
        sem_wait(&full_slots);
        pthread_mutex_lock(&mutex);
        cout<<"______________________________"<<endl;
        cout<<"Cosuming an item..."<<endl;
        sleep(0.5);
        int item = buffer[--index];
        buffer[index] = -1;
        cout<<"Consumed item with id : "<<item<<endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_slots);
}

int main() {
    pthread_mutex_init(&mutex, 0);
    sem_init(&empty_slots, 0, BUFFERSIZE);
    sem_init(&full_slots, 0, 0);
    // pthread_t producer;
    // pthread_create(&producer, 0, produce, 0);
    // pthread_t consumer;
    // pthread_create(&consumer, 0, consume, 0);
    // pthread_exit(0);
    pthread_t producers[5];
    pthread_t consumer; 
    cout<<"Enter your choice : "<<endl;
    cout<<"1. Create producer."<<endl;
    cout<<"2. Create consumer."<<endl;
    cout<<"3. Print buffer."<<endl;
    cout<<"3. Exit."<<endl;
    cout<<endl;
    while(1) {
        int choice; cout<<endl<<"Enter choice : "; cin>>choice;
        if(choice == 1) {
            if(nop<5) 
                pthread_create(&producers[nop++], 0, produce, 0);
            else cout<<"Only 5 producers at a time are allowed. try agiain after some time."<<endl;
        }
        else if(choice == 2) 
            pthread_create(&consumer, 0, consume, 0);
        else if(choice == 3) { 
            cout<<"______________________________"<<endl<<"buffer : ";
            for(int i : buffer) cout<<i<<" "; 
            cout<<endl;
        }
        else break;
    }
    pthread_exit(0);


}