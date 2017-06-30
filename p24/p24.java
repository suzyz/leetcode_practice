class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class p24 {
    public ListNode swapPairs(ListNode head) {
    	if(head==null || head.next==null) return head;

        ListNode p,q,r,s,ans=head.next;
        p=q=head;
        r=p.next;

        while(r!=null)
        {
        	s=r.next;
        	if(p!=q)
        	{
        		p.next=r;
        	}
        	q.next=s;
        	r.next=q;

        	if(s==null) break;

        	p=q;
        	q=s;
        	r=q.next;
        }
        return ans;
    }
}
