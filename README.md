# Assignment 5

Define a structure called Date with month, day and year as its only data members, Time with hour and minute as its only members and Event with desc (a c-string for description of maximum size 80), date (of type Date) and time (of type Time).

Write a readEvents() function that will keep asking the user if he or she wants to add a new event. As long as the user answers with a 'y' or 'Y', allocate memory dynamically for an Event structure, storing the pointer returned by new in the array of Event pointers and then read the Event data from the keyboard and store them in the Event just created. Dates should be entered like 5/21/20 and times as 10:15. When finished entering the Events, the function will return the number of Events entered.

Write a sort-desc() function to sort the Events by their description by rearranging the pointers (rather than the structures), by passing it the array of pointers and the number of Events created.  Use a swapPtrs() function to swap pointers.

Write another sort-date() function that takes the Events array and size and sorts them by date.

Write a linear search function that takes the array of sorted Event pointers, array size and a string and displays the first Event it finds whose description contains the specified string.  Consider using strstr() function to do linear search for a c-string within another c-string: 

if(strstr(events[i] -> desc, searchStr)) //search for searchStr string in events[i] -> desc

Write a binary search function that takes a month, as well as the array of pointers sorted by date and the array size and searches for and displays all Events found for the specified month. If not found, notify the user that it was not found.

Declare an array of Event pointers of MAX (50) size in main and pass it and the MAX size to readEvents function.

Call display() function from main that takes the array of Event pointers and number of Events created and prints the Events entered. Print Events like so:

Submit assignment by

11/30/2020    23:59

Dentist Appointment

11/28/2020    9:30

After sorting the array, print the list of Events again using the display function.

Then, read a string and find and display the Event containing the string in its description.  Or, if not found, print that it was not found.

Using the second sort function, sort the Events by date and print the array again.

Then, still in main, ask for and read a month and display all Events for the specified month using the binary search function.

Free all the dynamically allocated memory.

Free the array of Events dynamically allocated.

See the example below.

Required functions in addition to main:

readEvents(), display(), sort_desc(), sort_date, swapPtrs(), linsearch(), binsearch().

readEvents must return number of Events entered. linsearch and binsearch will print the Events found or that it was not found.  All functions, except swapPtrs, must take the array of Event pointers and array size. swapPtrs takes two Event pointers. No global variables. 

main must define the array of Event pointers and call the above functions and print the results (except for display and search functions which print the information in the function).

Submit the cpp file only.

Example run of the program:

Create an event [y/n]?    y

Enter description:  Submit assignment by

Enter date:   11/30/2020  

Enter time:    23:59

Create an event [y/n]?   y

Enter description:  Dentist Appointment

Enter date:    11/28/2020   

Enter time:    9:30

Create an event [y/n]?   n

Events entered:

Submit assignment by

Date:   11/30/2020   

Time:    23:59

Dentist Appointment

Date:    11/28/2020  

Time:    9:30

Events sorted by description:

Dentist Appointment

Date:    11/28/2020   

Time:    9:30

Submit assignment by

Date:   11/30/2020   

Time:    23:59

Enter a search string:  Dentist

Dentist Appointment

Date:    11/28/2020   

Time:    9:30

Events sorted by Date:

Dentist Appointment

Date:    11/28/2020   

Time:    9:30

Submit assignment by

Date:   11/30/2020   

Time:    23:59

Enter a month to list Events for: 11

Events for month 11:

Submit assignment by

Date:   11/30/2020   

Time:    23:59

Dentist Appointment

Date:    11/28/2020   

Time:    9:30

Press any key to continue.
