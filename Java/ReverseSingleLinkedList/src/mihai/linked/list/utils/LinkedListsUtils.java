package mihai.linked.list.utils;

import mihai.linked.list.LinkedList;
import mihai.linked.list.Node;

public final class LinkedListsUtils {

    /*
     * Given the head nodes of two lists, determine if the lists are equal.
     */
    public static boolean CompareLists(Node headA, Node headB) {

        // base case
        if (headA == null && headB == null) return true;
        else if (headA == null || headB == null) return false;

        if (headA.getData() == headB.getData())
            return CompareLists(headA.getNext(), headB.getNext());
        else
            return false;
    }


    /*
     * Given the head nodes of two sorted lists, merge them and return the head of the new list.
     */
    public static LinkedList MergeLists(LinkedList a, LinkedList b) {
        LinkedList newList = new LinkedList();
        newList.setHead(MergeListsRecursively(a.getHead(),b.getHead()));

        return newList;
    }

    private static Node MergeListsRecursively(Node headA, Node headB) {
        Node head;

        // base case
        if (headA == null) return headB;
        if (headB == null) return headA;

        if (headA.getData().compareTo(headB.getData()) < 0 ) {
            head = headA;
            head.setNext(MergeListsRecursively(headA.getNext(), headB));
        } else {
            head = headB;
            head.setNext(MergeListsRecursively(headA, headB.getNext()));
        }

        return head;
    }


    /*
     * Given a sorted linked list, remove the duplicates from it.
     */
    public static void RemoveDuplicates(LinkedList list) {
        Node head = list.getHead();
        if (head == null || head.getNext() == null) return;

        Node current = head;
        while (current.getNext() != null) {
            if (current.getData().equals(current.getNext().getData()))
                current.setNext(current.getNext().getNext());
            else
                current = current.getNext();
        }
    }
}
