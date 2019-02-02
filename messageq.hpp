#ifndef __MESSAGEQ_HPP__
#define __MESSAGEQ_HPP__

#include <mqueue.h>
#include <pthread.h>
#include <fcntl.h>
#include <string>
#include <string.h>

using namespace std;

template <class T>
class MessageQ {
    private:
        mqd_t qid;

    public:
        MessageQ() {
            struct mq_attr attr;
            attr.mq_maxmsg = 10;
            attr.mq_msgsize = sizeof(T);

            this->qid = mq_open("/server_otim1750",O_RDWR|O_CREAT,0666,&attr);

            if (this->qid==-1) throw "mq_open error!";
        }

        MessageQ(int x,int y) {
            this->qid = mq_open("/server_otim1750",O_RDWR);

            if (this->qid==-1) throw "mq_open error!";
        }

        MessageQ(pid_t pid) {
            struct mq_attr attr;
            attr.mq_maxmsg = 10;
            attr.mq_msgsize = sizeof(T);

            char* buffer = new char[200];
            sprintf(buffer,"/client_%d_otim1750",pid);

            this->qid = mq_open(buffer,O_RDWR|O_CREAT,0666,&attr);

            if (this->qid==-1) throw "mq_open error!";
        }

        MessageQ(pid_t pid, char x) {
            char* buffer = new char[200];
            sprintf(buffer,"/client_%d_otim1750",pid);

            this->qid = mq_open(buffer,O_RDWR);

            if (this->qid==-1) throw "mq_open error!";
        }

        void kill() {
            mq_close(this->qid);
            mq_unlink("/server_otim1750");
        }

        void close() {
            mq_close(this->qid);
        }

        void send(T message) {
            int ret;
            ret = mq_send(this->qid,(const char*) &message,sizeof(message),0);

            if (ret==-1) throw "mq_send error!";
        }

        bool receive(T& msg) {
            int ret;
            ret = mq_receive(this->qid,(char*)&msg,sizeof(T),0);

            if (ret==-1) return false;

            return true;
        }
};

#endif