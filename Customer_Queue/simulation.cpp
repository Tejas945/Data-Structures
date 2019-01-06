/*
 * simulation.cpp
 *
 *  Created on: 13-Dec-2018
 *      Author: Tejas Madappa
 */

#include "cashier.h"
#include "customer.h"
#include<queue>
#include <list>
#include <vector>
#include "stdlib.h"
#define numberofcashier 3
#define simulationTime 100
#define Max_Waiting_time 20


void simulation() {
	vector<cashier> cashiers;
	cashier lane;
	lane.isbusy = false;
	for (int i = 0; i < numberofcashier; i++)
		cashiers.push_back(lane);
	int numberofcustomers = 0;
//============================================
//     Read from Simulation.txt
//============================================
	queue<customer> customerQueue;
	{
		customer new_cust;
		ifstream fin;
		fin.open("simulation.txt");
		while (!fin.eof()) {
			fin >> new_cust;
			customerQueue.push(new_cust);
			numberofcustomers++;
		}
		fin.close();
	}
//========================================================================================
	cout<<"====================================="<<endl;
	cout<<"Cashier Counter Simulation Results:"<<endl;
	cout<<"====================================="<<endl;


	cout << "Number of customers " << numberofcustomers << endl;

	int *wait_time = new int[numberofcustomers];   //pointer to number of customers
	int sum = 0;
	float avg = 0.0;
	for (int clock = 1; clock <= simulationTime; clock++) {
		for (int i = 0; i < numberofcashier; i++) {
			if (cashiers[i].isbusy) {
				//waiting_time[i]=cashiers[i].checkout_time;
				//cout<<"im true";
				cashiers[i].checkout_time--;
				if (cashiers[i].checkout_time <= 0) {
					cashiers[i].isbusy = false;
					cout << "At time" << clock << " Cashier" << i
							<< " has finished serving Customer"
							<< cashiers[i].current_cust.customer_Number << endl;
				}
			}

			else if (cashiers[i].isbusy == false) {
				if (customerQueue.empty())
					continue;
				if (customerQueue.front().arrival_time > clock)
					continue;

				customer new_cust = customerQueue.front();
				customerQueue.pop();
				cashiers[i].isbusy = true;
				new_cust.service_start_time = clock;
				cout << "Clock="<<clock << endl;
				cout << "New customer arrival time=" <<new_cust.arrival_time << endl;
				cashiers[i].current_cust = new_cust;
				cashiers[i].checkout_time = new_cust.numberofItems;
				cout << "Cashier Number" << i << " is serving customer "
						<< cashiers[i].current_cust.customer_Number
						<< " at time " << new_cust.service_start_time << endl;
				cout << "Wait Time for "
						<< cashiers[i].current_cust.customer_Number << " is "
						<< clock - cashiers[i].current_cust.arrival_time
						<< endl;
				cout<<"=========================================================================="<<endl;
				wait_time[i] = clock - cashiers[i].current_cust.arrival_time;
				//cout<<wait_time[i]<<"Wait time array"<<endl;
				sum = sum + wait_time[i];
			}

		}
	}

//============================================
//   Calculating Average waiting time
//============================================
	avg = sum / numberofcustomers;
	cout << "Average wait time is " << avg<<endl;

	if (avg>Max_Waiting_time)
	{
		cout<<"There is need for extra Cashier Counter";
	}
	else{
		cout<<"=========================================================================="<<endl;
		cout<<"Everything is working , There is no need for extra Cashier Counter"<<endl;
		cout<<"Thankyou for using this system!!!"<<endl;
		cout<<"=========================================================================="<<endl;
	}
}

