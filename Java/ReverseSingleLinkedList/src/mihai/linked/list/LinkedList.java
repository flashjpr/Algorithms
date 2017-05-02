package mihai.linked.list;

/**
 * Created by flash on 29/04/2017.
 */
public class LinkedList {

    private Node head;

    void append(int data) {
        if (head == null) {
            head = new Node(data);
            return;
        }

        Node current = head;
        while (current.next != null)
            current = current.next;
        current.next = new Node(data);
    }

    public void prepend (int data) {
        Node newHead = new Node(data);
        newHead.next = head;
        head = newHead;
    }

    public void deleteWithValue (int data) {
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
    }

    public void printList() {
        Node current = head;
        while(current.next != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println(current.data);
    }

    public void reverse() {

        if (head == null) return;

        Node current = head;
        Node previous = null;
        Node next = null;
        while(current != null) {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

}
