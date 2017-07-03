/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class p61 {
    public ListNode rotateRight(ListNode head, int k) {
        if(k==0 || head==null) return head;
        ListNode cur=head;
        int n=1;
        while(cur.next!=null)
        {
            n++;
            cur=cur.next;
        }
        k%=n;
        if(k==0 || n==1) return head;
        cur.next=head;

        cur=head;
        for(int i=0;i<n-k-1;i++)
            cur=cur.next;
        
        head=cur.next;
        cur.next=null;
        return head;
    }
}