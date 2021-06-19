#include <iostream>

using namespace std;

struct Family
{
    string name;
    int hours;
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
            copy = head;
           
        }
        if (head == NULL)
        {
            
            head = newnode;
            head->hours = n;
            head->next = NULL;
            copy = head;
          
        }
    }
    Family *gethead() { return head; }
    Family *getcopy() { return copy; }
    friend void show(LinkedList & Object ); //This show function goes through each FAMILY node and shows family members;
    
};
void show(LinkedList & Object ) 
    {
        Family * copy = Object.head;
        cout << endl;

        while (copy != NULL)
        {
            cout << copy->hours;
            copy = copy->next;
        }
    }

int main()
{
    LinkedList one;
    LinkedList two;
    one.add(9);
    one.add(1);
    one.add(7);
    one.add(1);
    one.add(8);
    one.add(11);
    one.add(73);
    one.add(12);

    show(one);
    show(two);

    return 0;
}
