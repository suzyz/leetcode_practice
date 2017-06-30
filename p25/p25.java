class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class p25 {
    public ListNode reverseKGroup(ListNode head, int k) {
    	if(head==null) return head;

    	int count=0;
    	ListNode cur=head;
    	while(cur!=null && count<k)
    	{
    		cur=cur.next;
    		count++;
    	}
    	if(count!=k+1) return head;

    	cur=reverseKGroup(cur,k);

    	while(count>0)
    	{
    		ListNode tmp=head.next;
    		head.next=cur;
    		cur=head;
    		head=tmp;

    		count--;
    	}
    	return cur;
    }
}