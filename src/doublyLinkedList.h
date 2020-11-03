#ifndef __DOUBLYLINKEDLIST_H
#define __DOUBLYLINKEDLIST_H

typedef void* DoublyLinkedList;
typedef void* Info;
typedef void* Node;

/*
Instancia uma nova lista (malloc e retorna o void*)
*/
DoublyLinkedList create();
void insert(DoublyLinkedList lista, Info info);
Info getInfo(Node node);
Node getFirst(DoublyLinkedList lista);
Node getLast(DoublyLinkedList lista);
Node getPrevious(Node node);
Node getNext(Node node);
void insertBefore(DoublyLinkedList lista, Node node, Info info);
void insertAfter(DoublyLinkedList lista, Node node, Info info);
void removeNode(DoublyLinkedList lista, Node node);
void removeList(DoublyLinkedList lista);

#endif