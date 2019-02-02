#ifndef __SYNC_HPP__
#define __SYNC_HPP__

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

using namespace std;

class Sync {
    private:
        pthread_mutex_t mutex;

    public:
        Sync() {
            this->mutex = PTHREAD_MUTEX_INITIALIZER;
        }

        ~Sync() {
            pthread_mutex_destroy(&this->mutex);
        }

        bool lock() {
            return (pthread_mutex_trylock(&this->mutex)==0) ? true : false;
        }

        void unlock() {
            pthread_mutex_unlock(&this->mutex);
        }
};

#endif