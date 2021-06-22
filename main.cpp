#include <iostream>
#include <chrono>
using namespace std;

struct Family
{
    string name;
    int hours;
    int hours_accumulated;
    Family *next;
};

class LinkedList
{

private:
    Family *head;
    Family *copy;
    int number_of_nodes;
    Family *create()
    {
        Family *newnode = new Family;

        return newnode;
    }

public:
    LinkedList()
    {
        head = NULL;
        copy = head;
        int number_of_nodes = 0;
    }
    int accumulate_hours()
    {
        Family *copy = head;
        int answer;
        int accumulation = copy->hours;
        while (copy->next != NULL)
        {
            accumulation = accumulation + copy->next->hours;
            copy=copy->next;
        }
        answer = accumulation;
        return answer;
    }
    void add(int n) //The add function adds a sequence of FAMILY nodes to the end, which each have an array size 20
    {

        Family *newnode = create();

        if (head != NULL)
        {

            while (copy->next != NULL)
            {
                copy = copy->next;
            }
            copy->next = newnode;
            copy->next->hours = n;
            newnode->next = NULL;
            number_of_nodes++;

            copy = head;
        }
        if (head == NULL)
        {

            head = newnode;
            head->hours = n;
            head->next = NULL;
            number_of_nodes++;

            copy = head;
        }
    }
    Family *gethead() { return head; }
    Family *getcopy() { return copy; }
    friend void show(LinkedList &Object); //This show function goes through each FAMILY node and shows family members;
};
void show(LinkedList &Object)
{
    Family *copy = Object.head;
    cout << endl;

    while (copy != NULL)
    {
        cout << copy->hours << endl;
        copy = copy->next;
    }
    cout << "Hours accumulated: " << Object.accumulate_hours() << endl;
}

int main()
{

    LinkedList one;
    LinkedList two;

    int hours;
    string array[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (int i = 0; i < 7; i++)
    {
        cout << "How many hours did you work on: " << array[i];
        cin >> hours;
        one.add(hours);
    }

    show(one);

    return 0;
}
