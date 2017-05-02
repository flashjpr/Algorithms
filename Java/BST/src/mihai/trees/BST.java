package mihai.trees;

/**
 * Created by flash on 02/05/2017.
 */
class BST {

    private Node root;

    BST() {
        root = null;
    }

    void insert(int value) {
        Node newNode = new Node(value);
        if (root == null) {
            root = newNode;
            return;
        }
        insertNodeRecursively(root,newNode);
    }

    private void insertNodeRecursively(Node latestRoot, Node newNode) {
        // left subtree
        if (newNode.data < latestRoot.data) {
            // exit loop condition
            if (latestRoot.left == null) {
                latestRoot.left = newNode;
                return;
            }
            insertNodeRecursively(latestRoot.left, newNode);
        } else { // right subtree
            if (latestRoot.right == null) {
                latestRoot.right = newNode;
                return;
            }
            insertNodeRecursively(latestRoot.right, newNode);
        }
    }

    void printInOrder() {
        printInOrderRecursively(root);
        System.out.println();
    }

    private void printInOrderRecursively(Node currentRoot) {
        if (currentRoot == null) return;
        printInOrderRecursively(currentRoot.left);
        System.out.print(currentRoot.data + " ");
        printInOrderRecursively(currentRoot.right);
    }

    void printPreOrder() {
        printPreOrderRecursively(root);
        System.out.println();
    }

    private void printPreOrderRecursively(Node currentRoot) {
        if (currentRoot == null) return;
        System.out.print(currentRoot.data + " ");
        printPreOrderRecursively(currentRoot.left);
        printPreOrderRecursively(currentRoot.right);
    }

    void printPostOrder() {
        printPostOrderRecursively(root);
        System.out.println();
    }

    private void printPostOrderRecursively(Node currentRoot) {
        if (currentRoot == null) return;
        printPostOrderRecursively(currentRoot.left);
        printPostOrderRecursively(currentRoot.right);
        System.out.print(currentRoot.data + " ");
    }


    int findMinimum() {
        if (root == null) return 0;
        Node current = root;
        while (current.left != null)
            current = current.left;
        return current.data;
    }

    int findMaximum() {
        if (root == null) return 0;
        Node current = root;
        while (current.right != null)
            current = current.right;
        return current.data;
    }

}