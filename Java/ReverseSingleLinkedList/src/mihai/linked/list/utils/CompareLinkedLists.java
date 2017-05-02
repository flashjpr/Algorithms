package mihai.linked.list.utils;

import mihai.linked.list.Node;

public final class CompareLinkedLists {

    /*
     * Given the head nodes of two lists, determine if the lists are equal.
     */
    public static boolean CompareLists(Node headA, Node headB) {

        // base case
        if (headA == null && headB == null) return true;
        else if (headA == null || headB == null) return false;

        if (headA.data == headB.data)
            return CompareLists(headA.next, headB.next);
        else
            return false;
    }
}
