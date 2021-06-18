#include <iostream>

using namespace std;

struct Family
{
    string name;
    string array[10];
    Family *next;
};

class LinkedList
{

private:
    Family *head;
    Family *copy;
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
    }
    void add(string n, string a) //The add function adds a sequence of FAMILY nodes to the end, which each have an array size 20
    {
        Family *newnode = create();
        if (head == NULL)
        {
            head = newnode;
            head->array[0] = n;
            head->array[1] = n;
            head->next = NULL;
            copy = head;
        }
        if (head != NULL)
        {
            while (copy->next != NULL)
            {
                copy = copy->next;
            }
            copy->next = newnode;
            copy->next->array[0] = n;
            copy->next->array[1] = a;
            newnode->next = NULL;
            copy = head;
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
            cout << copy->array[0] << endl;
            cout << copy->array[1] << endl;
            copy = copy->next;
        }
    }
};

int main()
{
    LinkedList one;

    one.add("Jessica", "Analyssa");
    one.add("ANIMALS", "Dogs");
    one.add("Michael", "Jordan");
    one.add("Luis", "Daniel");

    one.show();

    return 0;
}
