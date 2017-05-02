package mihai.linked.list;

/**
 * Created by flash on 29/04/2017.
 */
public class LLApp {

    public static void main(String[] args) {

        LinkedList list = new LinkedList();
        list.append(2);
        list.append(23);
        list.append(25);
        System.out.println("Printed initial list: ");
        list.printList();
        System.out.println("Printed reversed list:");
        list.reverse();
        list.printList();
        list.deleteWithValue(23);
        System.out.println("Deleted node with value = 23");
        System.out.println("The resulted list: ");
        list.printList();
    }
}
