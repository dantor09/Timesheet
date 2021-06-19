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
    void show() //This show function goes through each FAMILY node and shows family members;
    {
        copy = head;
        cout << endl;

        while (copy != NULL)
        {
            for (int i = 0; i < 7; i++)
            {
                cout << copy->hours;
            }
            cout<<endl;
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
