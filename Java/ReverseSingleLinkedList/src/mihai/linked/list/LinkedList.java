package mihai.linked.list;

public class LinkedList {

    private Node head;

    public Node getHead() {
        return head;
    }

    private int size;

    void append(int data) {
        if (head == null) {
            head = new Node(data);
            return;
        }

        Node current = head;
        while (current.next != null)
            current = current.next;
        current.next = new Node(data);

        size++;
    }

    protected void prepend(int data) {
        Node newHead = new Node(data);
        newHead.next = head;
        head = newHead;

        size++;
    }

    void insertAtPosition(int data, int position) {
        Node toAdd = new Node(data);

        if (head == null) return;
        if (position == 0) {
            prepend(data);
            return;
        } else if (position > size) return;

        int currentPosition = 0;
        Node current = head;
        Node previous = null;

        while (currentPosition != position) {
            currentPosition++;
            previous = current;
            current = current.next;
        }
        toAdd.next = current;
        previous.next = toAdd;

        size++;
    }

    void deleteWithValue(int data) {
        if (head == null) return;
        if (head.data == data) {
            head = head.next;
            return;
        }

        Node current = head;
        while (current.next != null) {
            if (current.next.data == data) {
                current.next = current.next.next;
                return;
            }
            current = current.next;
        }

        size--;
    }

    void deleteAtPosition(int position) {
        if (head == null || position > size - 1) return;
        int currentPosition = 0;
        Node current = head;
        Node previous = null;

        while (currentPosition != position) {
            currentPosition++;
            previous = current;
            current = current.next;
        }
        if (previous != null) {
            previous.next = current.next;
        }
    }

    void printList() {
        Node current = head;
        while(current.next != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println(current.data);
    }

    void reverse() {
        if (head == null) return;

        Node current = head;
        Node previous = null;
        Node next;
        while(current != null) {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    int size() {
        return size;
    }

}
