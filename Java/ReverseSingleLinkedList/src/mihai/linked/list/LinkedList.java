package mihai.linked.list;

public class LinkedList<type extends Comparable<type>> {

    private Node<type> head;
    private int size = 0;

    void append(type data) {
        if (head == null) {
            head = new Node<type>(data);
            return;
        }

        Node<type> current = head;
        while (current.getNext() != null)
            current = current.getNext();
        current.setNext(new Node<type>(data));

        size++;
    }

    void prepend(type data) {
        Node<type> newHead = new Node<type>(data);

        newHead.setNext(head);
        head = newHead;

        size++;
    }

    void insertAtPosition(type data, int position) {
        Node<type> toAdd = new Node<type>(data);

        if (head == null) return;
        if (position == 0) {
            prepend(data);
            return;
        } else if (position > size) return;

        int currentPosition = 0;
        Node<type> current = head;
        Node<type> previous = null;

        while (currentPosition != position) {
            currentPosition++;
            previous = current;
            current = current.getNext();
        }
        toAdd.setNext(current);
        previous.setNext(toAdd);

        size++;
    }

    void deleteWithValue(type data) {
        if (head == null) return;
        if (head.getData().equals(data)) {
            head = head.getNext();
            size--;
            return;
        }

        Node<type> current = head;
        while (current.getNext() != null) {
            if (current.getNext().getData().equals(data)) {
                current.setNext(current.getNext().getNext());
                size--;
                return;
            }
            current = current.getNext();
        }
    }

    void deleteAtPosition(int position) {
        if (head == null || position > size - 1) return;
        int currentPosition = 0;
        Node<type> current = head;
        Node<type> previous = null;

        while (currentPosition != position) {
            currentPosition++;
            previous = current;
            current = current.getNext();
        }
        if (previous != null) {
            previous.setNext(current.getNext());
        }
    }

    void printList() {

        if (head == null) return;

        Node<type> current = head;
        while(current.getNext() != null) {
            System.out.print(current.getData() + " -> ");
            current = current.getNext();
        }
        System.out.println(current.getData());
    }

    void reverse() {
        if (head == null) return;

        Node<type> current = head;
        Node<type> previous = null;
        Node<type> next;
        while(current != null) {
            next = current.getNext();
            current.setNext(previous);
            previous = current;
            current = next;
        }
        head = previous;
    }

    int size() {
        return size;
    }

    type elementAtPosition(int position) {
        if (head == null) return null;
        if (position >=0 && position > size -1) return null;
        Node<type> current = head;
        int currentPosition = 0;
        while (currentPosition != position) {
            currentPosition++;
            current = current.getNext();
        }
        return current.getData();
    }

    public void setHead(Node<type> head) {
        this.head = head;
    }
    public Node<type> getHead() {
        return head;
    }

}
