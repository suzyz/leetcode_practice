class ListNode {
    int val;
    ListNode next;
  	ListNode(int x) { val = x; }
}
 
public class p83 {
    public ListNode deleteDuplicates(ListNode head) {
    	ListNode p=head;
        while(p!=null)
        {
        	if(p.next==null) break;
        	if(p.val==p.next.val) p.next=p.next.next;
        	else p=p.next;
        }
        return head;
    }
}