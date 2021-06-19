#include <iostream>

using namespace std;

struct Family
{
    string name;
    int array[7];
    Family *next;
};

class LinkedList
{

private:
    Family *head;
    Family *copy;
    int weekday;
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
        weekday = 0;
    }
    void add(int n) //The add function adds a sequence of FAMILY nodes to the end, which each have an array size 20
    {
        if (weekday == 8)
        {
            weekday = 0;
        }

        Family *newnode = create();

        if (head != NULL)
        {
            cout << "In here "
                 << "Name: " << n << endl;
            while (copy->next != NULL)
            {
                copy = copy->next;
            }
            copy->next = newnode;
            copy->next->array[weekday] = n;
            newnode->next = NULL;
            copy = head;
            weekday++;
        }
        if (head == NULL)
        {
            cout << "In here "
                 << "Name: " << n << endl;
            head = newnode;
            head->array[weekday] = n;
            head->next = NULL;
            copy = head;
            weekday++;
        }
    }
    Family *gethead() { return head; }
    Family *getcopy() { return copy; }
    void show() //This show function goes through each FAMILY node and shows family members;
    {
        copy = head;
        cout << endl;

        while (copy != NULL)
        {
            for (int i = 0; i < 7; i++)
            {
                cout << copy->array[i] << endl;
            }
            copy = copy->next;
        }
    }
};

int main()
{
    LinkedList one;

    one.add(9);
    one.add(1);
    one.add(7);
    one.add(1);

    one.show();

    return 0;
}
