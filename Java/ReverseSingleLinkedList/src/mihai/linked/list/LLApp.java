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
        list.printList();
        list.reverse();
        list.printList();
        list.deleteWithValue(23);
        list.printList();
    }
}
