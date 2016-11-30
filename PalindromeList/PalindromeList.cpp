/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public bool IsPalindrome(ListNode head) {
        if (head == null || head.next == null)
        {
            return true;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        ListNode subHead = null;
        while (fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        if (fast.next != null)
        {
            subHead = slow.next.next;
            
        }
        else
        {
            subHead = slow.next;
        }
        slow = null;
        ListNode reverseHead = ReverseList(subHead);
        while (head != null && reverseHead != null)
        {
            if (head.val != reverseHead.val)
            {
                return false;
            }
            head = head.next;
            reverseHead = reverseHead.next;
        }
        return true;
    }
    public ListNode ReverseList(ListNode head)
    {
        if (head.next == null)
        {
            return head;
        }
        ListNode current = head;
        ListNode prev = null;
        ListNode temp = null;
        while (current!= null && current.next != null)
        {
            temp = current.next;
            current.next = prev;
            prev = temp;
            temp = current;
            current = prev.next;
            prev.next = temp;
        }
        if (current != null)
        {
            current.next = prev;
        }
        else
        {
            current = prev;
        }
        return current;
    }
}