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

// Retrieve
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
    
    
}


ListNodePtr listNodeCreate (Element e){
    ListNodePtr pn = new ListNode;
    pn->key = e;
    pn->next = nullptr;
    return pn;
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