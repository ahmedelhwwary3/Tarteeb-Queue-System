#pragma once
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "clsDate.h"
using namespace std;

class clsQueueLine
{
private:
	string _Prefix;
	int _TotalTickets = 0;
	int _ServiceTime;
	class clsTicket
	{
	private:
		string _Time;
		string _Prefix;
		int _Number = 0;
		int _ServedClients = 0;
		int _ServiceTime = 0;

	public:
		clsTicket(string Prefix, int Number, int ServedClients, int ServiceTime)
		{
			_Time = clsDate::GetSystemDateTimeString();
			_Prefix = Prefix;
			_Number = Number;
			_ServedClients = ServedClients;
			_ServiceTime = ServiceTime * (Number - 1);
		}
		string Time()
		{
			return _Time;
		}
		string Prefix()
		{
			return _Prefix;
		}
		int ServiedClients()
		{
			return _ServedClients;
		}
		int ServiceTime()
		{
			return _ServiceTime;
		}
		int Number()
		{
			return _Number;
		}
		int WaitingClients()
		{
			return Number() - _ServedClients;
		}
		int ServerClients()
		{
			return _ServedClients;
		}
		string FullNumber()
		{
			return Prefix() + to_string(Number());
		}
		void Print()
		{
			cout << "\t\t\t\t\t----------------------------------\n";
			cout << "\t\t\t\t\t\t\t" << FullNumber() << endl;
			cout << endl;
			cout << "\t\t\t\t\t\t" << Time() << endl;
			cout << "\t\t\t\t\t\tWaiting Clients = " << WaitingClients() << endl;
			cout << "\t\t\t\t\t\tServing Time In " << to_string(ServiceTime()) << " Minutes.\n";
			cout << "\t\t\t\t\t----------------------------------\n";
		}
	};


public:
	queue<clsTicket>MyQueue;

	clsQueueLine(string Prefix, int ServiceTime)
	{
		_TotalTickets = 0;
		_Prefix = Prefix;
		_ServiceTime = ServiceTime;
	}
	void IssueTicket()
	{
		_TotalTickets++;
		//Ticket Number = _TotalTickets
		clsTicket Ticket(_Prefix, _TotalTickets, ServedClients(), _ServiceTime);
		MyQueue.push(Ticket);
	}
	int ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}
	int WaitingClients()
	{
		return MyQueue.size();//Because After Finish Serving Client,
		//the Queue pops Ticket and move to the next one
	}
	bool ServeTheNextClient()
	{
		if (WaitingClients() == 0)
			return false;
		MyQueue.pop();
		return true;
	}
	string WhoIsTheCurrentClient()
	{
		if (MyQueue.empty())
			return "No Clients!";
		return MyQueue.front().FullNumber();
	}
	void PrintQueueInfo()
	{
		cout << "\t\t\t\t\t----------------------------------\n";
		cout << "\t\t\t\t\t\t\tQueue Info\n";
		cout << "\t\t\t\t\t----------------------------------\n";
		cout << "\t\t\t\t\t\tPrefix          : " << Prefix() << endl;
		cout << "\t\t\t\t\t\tTotal Tickets   : " << TotalTickets() << endl;
		cout << "\t\t\t\t\t\tServed Clients  : " << ServedClients() << endl;
		cout << "\t\t\t\t\t\tWaiting Clients : " << WaitingClients() << endl;
		cout << "\t\t\t\t\t----------------------------------\n";
	}
	int TotalTickets()
	{
		return _TotalTickets;
	}
	string Prefix()
	{
		return _Prefix;
	}
	void PrintTicketsNumbersLTR()
	{
		queue<clsTicket>TempQueue = MyQueue;
		cout << "\t\t\t\t\tClients Tickets:";
		if (TempQueue.empty())
		{
			cout << " No Tickets!\n";
		}
		while (!TempQueue.empty())
		{
			cout << TempQueue.front().FullNumber() << "-->";
			TempQueue.pop();
		}
		cout << endl;
	}
	void PrintTicketsNumbersRTL()
	{
		queue<clsTicket>TempQueue = MyQueue;
		stack<clsTicket>TempStack;


		cout << "\t\t\t\t\tClients Tickets:";
		if (TempQueue.empty())
		{
			cout << " No Tickets!\n";
		}
		while (!TempQueue.empty())
		{
			TempStack.push(TempQueue.front());
			TempQueue.pop();
		}
		while (!TempStack.empty())
		{
			cout << TempStack.top().FullNumber() << "-->";
			TempStack.pop();
		}
		cout << endl;
	}
	void PrintAllTicketsInfo()
	{
		queue<clsTicket>TempQueue = MyQueue;
		while (!TempQueue.empty())
		{
			TempQueue.front().Print();
			cout << endl;
			TempQueue.pop();
		}
	}

};


