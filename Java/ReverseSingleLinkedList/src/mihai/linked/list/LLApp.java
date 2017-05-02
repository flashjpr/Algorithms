package mihai.linked.list;


import mihai.linked.list.utils.CompareLinkedLists;

import java.util.Collections;

public class LLApp {

    public static void main(String[] args) {

        LinkedList list = new LinkedList();

        System.out.println("Printed initial list: ");
        list.append(2);
        list.append(23);
        list.append(25);
        list.prepend(14);
        list.printList();

        System.out.println("Printed reversed list:");
        list.reverse();
        list.printList();

        System.out.println("Deleted node with value = 23");
        list.deleteWithValue(23);
        System.out.println("The resulted list: ");
        list.printList();

        System.out.println("Insert 1 at position 0:");
        list.insertAtPosition(1,0);
        list.printList();
        System.out.println("Insert 2 at position 3:");
        list.insertAtPosition(2,3);
        list.printList();

        System.out.println("The size the list is: " + list.size());

        System.out.println("Delete item at position 4");
        list.deleteAtPosition(4);
        list.printList();

        LinkedList a = new LinkedList();
        LinkedList b = new LinkedList();
        System.out.println(CompareLinkedLists.CompareLists(a.getHead(),b.getHead()));
        a.prepend(10101);
        b.prepend(10101);
        System.out.println(CompareLinkedLists.CompareLists(a.getHead(),b.getHead()));
    }
}
