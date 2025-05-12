

#include <iostream>
#include "clsMyString.h"
#include "clsQueueLine.h"
using namespace std;

int main()
{
    clsQueueLine VIPsQueueLine("0A", 5);
    VIPsQueueLine.IssueTicket();
    VIPsQueueLine.IssueTicket();
    VIPsQueueLine.IssueTicket();
    VIPsQueueLine.IssueTicket();
    VIPsQueueLine.PrintQueueInfo();
    VIPsQueueLine.PrintTicketsNumbersLTR();
    VIPsQueueLine.PrintTicketsNumbersRTL();
    cout << endl << endl;
    VIPsQueueLine.PrintAllTicketsInfo();
    VIPsQueueLine.ServeTheNextClient();
    VIPsQueueLine.ServeTheNextClient();
    VIPsQueueLine.PrintQueueInfo();
    system("pause>0");

    return 0;
}

