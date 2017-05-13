package mihai.linked.list;

public class Node<type extends Comparable<type>> {

    private type data;
    private Node next;

    public Node(type data) {
        this.data = data;
    }

    public type getData() {
        return data;
    }

    public void setData(type data) {
        this.data = data;
    }

    public Node<type> getNext() {
        return next;
    }

    public void setNext(Node<type> next) {
        this.next = next;
    }

    // types = type args
//
//    public int compareTo(type data) {
//
//        final int EQUAL = 0;
//        final int LESS = -1;
//        final int GREATER = 1;
//
//        if (this.data == data) {
//            return EQUAL;
//        } else if ()
//    }
}
