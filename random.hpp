#ifndef __RANDOM_HPP__
#define __RANDOM_HPP__

#include <iostream>
#include <string>
#include <deque>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <limits.h>
#include <time.h>

using namespace std;

class Random {
    public:
        Random() {
            srand(time(0));
        }

        int rng(int max) {
            return random()%max;
        }

        int rng(int min, int max) {
            return (random()+min)%(max+1);
        }
};

#endif