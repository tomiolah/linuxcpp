#ifndef __SHELL_HPP__
#define __SHELL_HPP__

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
#include "random.hpp"


using namespace std;

class Shell {
    private:
        string exec_path;

    public:
        Shell() {
            this->exec_path = "./src/script.sh ";
        }

        deque<string> run(date x) {
            deque<string> out;

            char* bufp = new char[1024];
            sprintf(bufp,"./src/script.sh %d%d%d%d%d%d%d%d%d%d%d%d%d%d",x.y[0], x.y[1], x.y[2], x.y[3], x.m[0], x.m[1], x.d[0], x.d[1], x.t.h[0], x.t.h[1], x.t.m[0], x.t.m[1], x.t.s[0], x.t.s[1]);

            FILE * op;
            op = popen(bufp,"r");
            delete [] bufp;

            char buffer[1024];

            while (fscanf(op,"%s",buffer)>0) {
                string seged(buffer);
                out.push_back(seged);
            }

            pclose(op);

            return out;
        }

        deque<string> run(string f) {
            cout << "\n\nARGS: " << f << "\n\n";

            deque<string> out;
            char* bufp = new char[1024];
            sprintf(bufp,"./src/script.sh %s",f.c_str());

            cout << "\n\nPATH: " << bufp << "\n\n";

            FILE * op;
            op = popen(bufp,"r");
            delete [] bufp;

            cout << "OK";
            char buffer[1024];

            while (fscanf(op,"%s",buffer)>0) {
                string seged(buffer);
                out.push_back(seged);
            }

            pclose(op);

            return out;
        }
};

#endif