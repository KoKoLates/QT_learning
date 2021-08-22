#include "thread.h"

MyThread::MyThread()
{

}

void MyThread::run(){
    int count = 0;
    QList<int>numbersList; // declare a QList to store the random data
    srand(time(NULL));
    for(int i=0; i<10; i++){
        int num = rand()%10 + count*10;
        numbersList<<num;
        count++;
    }
    numbersList<<100;
    for(int i=0; i<numbersList.size(); i++){
        emit sendNum(numbersList[i]); // emit the data to the MainWindow
        QThread::msleep(1500); // wait for 1500 ms
    }
    emit done(); // emit the signal that the process is done
}
