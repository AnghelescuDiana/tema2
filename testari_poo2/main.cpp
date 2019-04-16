/*
Anghelescu Diana Livia
Grupa211
Tema 2 ex.4
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <conio.h>
#define TipI   int
using namespace std;

class node
{
public:
    TipI info;
    struct node *next;
    struct node *prev;

    node();
    node(TipI info,node* next=0,node* prev=0);
    TipI getInfo();
    void setInfo(TipI info);
    node* getNext();
    void setNext(node* next);
    int operator == (node&);
}*start;

class double_llist
{
    public:
        void create_list(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        friend ostream& operator<<(ostream& ,const node *);
        void count();
        void reverse();
        int isEmpty();
        ~double_llist();
        double_llist()
        {
            start = NULL;
        }
};

 /*Constructor implicit*/
    node::node(){
     next=0;
     prev=0;
    }

    /*Constructor de initializare*/
    node::node(TipI info, node* next, node* prev){
     this->info=info;
     this->next=next;
     this->prev=prev;
    }


    TipI node::getInfo(){
     return info;
   }

    void node::setInfo(TipI info){
         this->info=info;
    }

    node* node::getNext(){
     return next;
    }

   void node::setNext(node* next){
         this->next=next;
    }

    int node::operator == (node &n){
     return this->info==n.info;
    }
/*
 Creez lista dublu inlantuita
 */
void double_llist::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

/*
Insereaza inaintea listei
 */
void double_llist::add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"Creaza Lista"<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element inserat"<<endl;
}

/*
Inserare la sfarsit de lista
 */
void double_llist::add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"Creare lista"<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"Sunt mai putin de ";
            cout<<pos<<" elemente"<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element inserat"<<endl;
}

/*
 Sterge un element din lista
 */
void double_llist::delete_element(int value)
{
    struct node *tmp, *q;
     /*elementul din fata sters*/
    if (start->info == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout<<"Element sters"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /*elementul din mijloc sters*/
        if (q->next->info == value)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element sters"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
     /*ultimul element sters*/
    if (q->next->info == value)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element sters"<<endl;
        return;
    }
    cout<<"Nodul "<<value<<" nu exista"<<endl;
}

/*
Afiseaza elementele din lista
 */
void double_llist::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"Lista goala"<<endl;
        return;
    }
    q = start;
    cout<<"Lista dubla este :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
 std::ostream& operator<<(std::ostream& output,const node *q)
{

    if (start == NULL)
    {
        cout<<"Lista goala"<<endl;
        //return;
    }
    q = start;
    cout<<"Lista dubla este :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
/*
contorizator
 */
void double_llist::count()
{
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Contor lista: "<<cnt<<endl;
}

/*
 lista inversata
 */
void double_llist::reverse()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    cout<<"Lista rasturnata"<<endl;
}

/* Concatenarea a doua liste

double_llist double_llist::operator+(double_llist 1){
    double_llist 2;
    int k = 0;
    2.count(k);
    node_dublu *p ;
    int i;
    for(i = 0; i < 2.count(); i++){
        2.add_after(p->info(), i);
        p = p->next();
    }


    for(int k = 0; k < 1.count(); k++){
        2.push(p->info(), i);
        i++;
        p = p->next();
    }

    return 2;
}

*/
int main()
{
    int choice, element, position;
    double_llist dl;
    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Aplicatii lista dubla inlantuita"<<endl;
        cout<<endl<<"----------------------------"<<endl;
        cout<<"1.Creare Nod"<<endl;
        cout<<"2.Adauga la inceput de lista"<<endl;
        cout<<"3.Adauga la sfarsit de lista"<<endl;
        cout<<"4.Stergere"<<endl;
        cout<<"5.Afisare"<<endl;
        cout<<"6.Contorizare"<<endl;
        cout<<"7.Lista inversata"<<endl;
        cout<<"8.Iesire"<<endl;
        cout<<"Introduce ti selectorul : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Introduce ti element: ";
            cin>>element;
            dl.create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Introduce ti element: ";
            cin>>element;
            dl.add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Introduce ti elementul dorit: ";
            cin>>element;
            cout<<"Inserati Elementul dupa pozitia: ";
            cin>>position;
            dl.add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {
                cout<<"Lista goala, nu are elemente"<<endl;
                break;
            }
            cout<<"Introduce ti elemtul care sa fie sters: ";
            cin>>element;
            dl.delete_element(element);
            cout<<endl;
            break;
        case 5:
            dl.display_dlist();
            cout<<endl;
            break;
        case 6:
            dl.count();
            break;
        case 7:
            if (start == NULL)
            {
                cout<<"Lista e goala"<<endl;
                break;
            }
            dl.reverse();
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"eroare!"<<endl;
        }
    }
    return 0;
}

/* Destructorul clasei listei duble*/
    double_llist::~double_llist(){
       node *p=start;
       node *q;
       //se elibereaza spatiul de memorie rezervat elementelor listei/
       while(p!=0){
          q = p;
        p = p->next;
          delete q;
       }
       start = 0;
    }

    int double_llist::isEmpty(){
     return start==0;
    }
