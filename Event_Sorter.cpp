//CS_117_20895SP21V
//Assignment 5
//Jordan Cole


#include <iostream>
#include <string.h>


using namespace std;


struct Date																	//Stucture definitions
{
	int month;
	int day;
	int year;
};

struct Time
{
	int hour;
	int minute;
};

struct Event
{
	char desc[80];
	Date date;
	Time time;
};


int readEvents(Event* user_Events[], int max)								//Function to read user events
{
	char user_choice = 'n';
	char slash_take;
	char colon_take;
	int i = 0;
	
	while (true && i < max)
	{
		cout << "Create an event [y/n]? ";
		cin >> user_choice;

		if (user_choice == 'y' || user_choice == 'Y')
		{
			user_Events[i] = new Event;

			cout << "Enter the description: ";
			cin.ignore();
			cin.getline(user_Events[i]->desc, sizeof(user_Events[i]->desc));

			cout << "Enter date: ";
			cin >> user_Events[i]->date.month >> slash_take >> user_Events[i]->date.day >> slash_take >> user_Events[i]->date.year;

			cout << "Enter time: ";
			cin >> user_Events[i]->time.hour >> colon_take >> user_Events[i]->time.minute;
		}
		
		else
		{
			break;
		}
		
		i++;
	}

	return i;
}


void sortByDesc(Event* user_Events[], int events_num)						//Function to sort events by desc
{
	bool swapped;

	do
	{
		swapped = false;
		for (int i = 0; i < events_num - 1; i++)
		{
			if (strcmp(user_Events[i]->desc, user_Events[i + 1]->desc) > 0)
			{
				swap(user_Events[i], user_Events[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);
}


void sortByDate(Event* user_Events[], int events_num)						//Function to sort events by date
{
	bool swapped;

	do
	{
		swapped = false;
		for (int i = 0; i < events_num - 1; i++)
		{
			if ((user_Events[i]->date.day > user_Events[i + 1]->date.day) &&
				(user_Events[i]->date.month > user_Events[i + 1]->date.month) &&
				(user_Events[i]->date.year > user_Events[i + 1]->date.year))
			{
				swap(user_Events[i], user_Events[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);
}


void linSearch(Event* user_Events[], int events_num, char* spec_str)		//Function to find desc containing specified string
{
	for (int i = 0; i < events_num; i++)
	{
		if (strstr(user_Events[i]->desc, spec_str) != NULL)
		{
			cout << user_Events[i]->desc << endl;
			cout << "Date: " << user_Events[i]->date.month << "/" << user_Events[i]->date.day << "/" << user_Events[i]->date.year << endl;
			cout << "Time: " << user_Events[i]->time.hour << ":" << user_Events[i]->time.minute << endl;
		}
	}
}


void binSearch(Event* user_Events[], int num, int month)					//Function to search events by month
{
	int l = 0;
	int r = num - 1;
	int result = -1;
	
	cout << "Events for month " << month << ":" << endl;

	while (l <= r)
	{
		int m = (l + r) / 2;

		if (user_Events[m]->date.month == month)
		{
			result = m;
			cout << user_Events[m]->desc << endl;
			cout << "Date: " << user_Events[m]->date.month << "/" << user_Events[m]->date.day << "/" << user_Events[m]->date.year << endl;
			cout << "Time: " << user_Events[m]->time.hour << ":" << user_Events[m]->time.minute << endl;
		}
		
		if (month < user_Events[m]->date.month)
		{
			r = m - 1;
		}

		else
		{
			l = m + 1;
		}
	}

	if (result == -1)
	{
		cout << "Event for month " << month << " not found.";
	}
}


void display(Event* user_Events[], int events_num)							//Function to display results
{
	for (int i = 0; i < events_num; i++)
	{
		cout << user_Events[i]->desc << endl;
		cout << "Date: " << user_Events[i]->date.month << "/" << user_Events[i]->date.day << "/" << user_Events[i]->date.year << endl;
		cout << "Time: " << user_Events[i]->time.hour << ":" << user_Events[i]->time.minute << endl;
	}
}


int main()
{
	Event* user_Events[50];
	char str[200];
	int num = readEvents(user_Events, 50);
	int month;

	cout << "Events entered:" << endl;
	display(user_Events, num);

	cout << "Events sorted by description:" << endl;
	sortByDesc(user_Events, num);
	display(user_Events, num);

	cout << "Enter a search string: ";
	cin.ignore();
	cin.getline(str, sizeof(str));
	linSearch(user_Events, num, str);

	cout << "Events sorted by Date:" << endl;
	sortByDate(user_Events, num);
	display(user_Events, num);

	cout << "Enter a month to list Events for: ";
	cin >> month;
	binSearch(user_Events, num, month);
	
	return 0;
}
