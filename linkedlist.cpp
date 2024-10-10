#include <stdio.h>

template <typename T>
class Node {
public:
    T m_data;
    Node* m_next;
};

template <typename T>
class LinkedList {

    private:
    Node<T>* m_headP;
    Node<T>* m_tailP;

    public:
    LinkedList() {
        m_headP=NULL;
        m_tailP=NULL;
    }

    void add(T data) {
        Node<T>* newData = new Node<T>;
        newData->m_data=data;
        newData->m_next=NULL;

        if (m_headP!=NULL) {
            // length > 0
            m_tailP->m_next=newData;
            m_tailP=newData;
        } else {
            // length == 0
            m_headP=newData;
            m_tailP=newData;
        }

    }

    T getData(int index) {
        Node<T>* pointer = m_headP;
        int count = 0;
        while(count != index) {
            if (pointer==NULL) {
                // TODO how to raise an array index exception in C++??
                return 0;
            }
            pointer = pointer->m_next;
            count++;
        }
        return pointer->m_data;
    }

    ~LinkedList() { 
        Node<T>* pointer = m_headP;
        Node<T>* nextNode = NULL;

        while (pointer != NULL) {
            nextNode = pointer->m_next;
            delete pointer;
            pointer = nextNode;
        }
    }

};

int main() {
    LinkedList<int> list = LinkedList<int>();
	for (int i=0; i<7; i++) {
        list.add(i*100);
    }

    for (int i=0; i<7; i++) {
        printf("%d\n", list.getData(i));
    }
}