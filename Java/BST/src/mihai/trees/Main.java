package mihai.trees;

public class Main {

    public static void main(String[] args) {

        BST bst = new BST();
        bst.insert(4);
        bst.insert(2);
        bst.insert(6);
        bst.insert(3);
        bst.insert(1);
        bst.insert(5);
        bst.insert(7);

        System.out.print("BST in order: ");
        bst.printInOrder();

        System.out.print("BST pre order: ");
        bst.printPreOrder();

        System.out.print("BST post order: ");
        bst.printPostOrder();

        System.out.println("Minimum in the tree = " + bst.findMinimum());
        System.out.println("Maximum in the tree = " + bst.findMaximum());
    }
}
