#include <iostream>

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
        number_of_nodes = 0;
        
    }
    void accumulate_hours(int hours)
    {
        if(number_of_nodes >=1)
        {
        copy->hours_accumulated = copy->hours + copy->hours;
        }

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
            accumulate_hours(copy->hours);
            copy = head;
           
        }
        if (head == NULL)
        {
            
            head = newnode;
            head->hours = n;
            head->next = NULL;
            number_of_nodes++;
            accumulate_hours(copy->hours);
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
