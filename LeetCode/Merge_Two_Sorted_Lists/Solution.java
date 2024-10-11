package leetcode.Merge_Two_Sorted_Lists;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode finalList = new ListNode();
        ListNode lastPointer = finalList;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                lastPointer.next = list1;
                list1 = list1.next;
            } else {
                lastPointer.next = list2;
                list2 = list2.next;
            }
            lastPointer = lastPointer.next;
        }

        if (list1 != null) {
            lastPointer.next = list1;
        }

        if (list2 != null) {
            lastPointer.next = list2;
        }
        return finalList.next;
    }
}
