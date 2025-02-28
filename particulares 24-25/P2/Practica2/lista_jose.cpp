#ifndef LIST
#define LIST

#include <cstdint>
#include <string>
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//                 Typedefs/Using + Declaraciones adelantadas                //
///////////////////////////////////////////////////////////////////////////////
using Element = char; // Hasta que veamos genericidad usaremos estos
    // typedef.
using Position = int64_t;
const Position NOPOS = -1;

struct ListNode;
using  ListNodePtr = ListNode*;

///////////////////////////////////////////////////////////////////////////////
//                                    Node                                   //
///////////////////////////////////////////////////////////////////////////////
struct ListNode {
    Element key;
    ListNodePtr next;
};

ListNodePtr listNodeCreate (Element e);

static std::string listNodeToString (ListNodePtr p) {
    std::string s;
    return s + p->key;
}

///////////////////////////////////////////////////////////////////////////////
//                                    List                                   //
///////////////////////////////////////////////////////////////////////////////
struct List;
using  ListPtr = List*;

struct List {
    ListNodePtr head;
};

// Constructor por defecto
ListPtr listCreate        ();

// Inicializacion de datos a valores seguros
void listInit             (ListPtr l);

// Insert
bool listInsert           (ListPtr l, Element x, Position i);

// Locate
Position listLocate       (ListPtr l, Element x);

// Retrieve (!!! Zu hause gehen !!!)
ListNodePtr listRetrieve  (ListPtr l, Position i);

// Elimina el elemento en la posicion p
bool listRemove           (ListPtr l, Position p);

// Vacia la lista
void listMakeNull         (ListPtr l);

// Primer elemento
ListNodePtr listFirst     (ListPtr l);

// Devuelve la lista como una cadena usando 'c' como separador
[[maybe_unused]]
static std::string listToString (ListPtr l, char c) {
    std::string s;

    for (ListNodePtr n = l->head; n != nullptr; n = n->next)
        s += c + listNodeToString (n);

    return s;
}

// Devuelve el número de elementos en la lista
uint64_t listSize         (ListPtr l);

#endif

ListPtr listCreate(){
    ListPtr lptr = new List;
    lptr->head = nullptr;
    return lptr;
}

void listInit(ListPtr l){
    if(l != nullptr){
        l->head = nullptr;
    }
}

// i = 1, tengo que insertar al principio de la lista, porque la lista se numera desde 1.
// i > len(lista), tengo que insertar al final de la lista.
// i < 1, no inserto, esta mal, no es posicion valida.
bool listInsert(ListPtr l, Element x, Position i){
    bool inserted = false;
    ListNodePtr pta, ptl, ptn;
    int64_t c;

    if(l != nullptr){
        if(i >= 1){
            c = 1;
            pta = nullptr;
            ptl = l->head;
            while(ptl && c < i){
                pta = ptl;
                ptl = ptl->next;
                c++;
            }
            ptn = listNodeCreate(x);
            ptn->next = ptl;
            if(!pta){
                l->head = ptn;
            }
            else{
                pta->next = ptn;
            }
            inserted = true;
        }
    }
    return inserted;
}

// Locate
Position listLocate(ListPtr l, Element x){
    Position p = NOPOS;
    ListNodePtr ptl;
    Position actual;

    if(l){
        actual = 1; // contador por la posicion por la que voy.
        ptl = l->head;
        while(ptl && p == NOPOS){
            if(ptl->key == x){
                p = actual;
            }
            else{
                ptl = ptl->next;
                actual++;
            }
        }
    }
    return p;
}

// Elimina el elemento en la posicion p
bool listRemove(ListPtr l, Position p){
    bool removed = false;
    Position c;
    ListNodePtr pta, ptl;

    if(l != nullptr){
        c = 1;
        pta = nullptr;
        ptl = l->head;
        while(ptl && c < p){
            pta = ptl;
            ptl = ptl->next;
            c++; // avanzo en la lista tantas veces como indique p - 1
        }
        if(ptl){
            if(pta == nullptr){ // if(ptl == l->head) // p == 1
                l->head = ptl->next; // l->head = l->head->next;
            }
            else{
                pta->next = ptl->next;
            }
            delete ptl;
        }
    }
    return removed;
}


// Primer elemento
ListNodePtr listFirst(ListPtr l){
    ListNodePtr p = nullptr;
    if(l){
        p = l->head;
    }
    return p;
}

uint64_t listSize(ListPtr l){
    uint64_t lsize = 0;
    ListNodePtr p;
    if(l){
        p = l->head;
        while(p){
            lsize++;
            p = p->next;
        }
    }
    return lsize;
}

ListNodePtr listNodeCreate (Element e){
    ListNodePtr pn = new ListNode;
    pn->key = e;
    pn->next = nullptr;
    return pn;
}

// Vacia la lista
void listMakeNull(ListPtr l){
    ListNodePtr pborrar;
    if(l){
        while(l->head){
            pborrar = l->head;
            l->head = l->head->next;
            delete pborrar;
        }
    }
}



int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    ListPtr l = listCreate();

    for (char c='g'; c >= 'a'; c--)
        listInsert (l, c, 1);

    //listInsert (l, 'z', 1);

    auto s = listToString (l,':');
    auto p = listLocate (l, 'e');
    auto r = s == ":a:b:c:d:e:f:g" and p == 5;

    listMakeNull(l);
    delete l;
    //std::cout << s;

    return r ? 0 : 1;
}

